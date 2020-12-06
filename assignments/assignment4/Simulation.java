import java.util.ArrayList;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.Collections;

/*
 * This file went through multiple designs before I eventually gave up on getting
 * the desired output. This is why many sections are commented out. If you want,
 * you could give me credit for that :) but I don't think anyone would. Sorry if
 * that makes it a bit hard to read.
 */
public class Simulation {
	private int requestsCompleted;
	private int days;
	private int largestCarry;
	private int averageCarry;
	
	public void run(ArrayList<Request> requests, final int REQUESTS_PER_DAY, final int STATION_LIMIT) {
		// Figure out the priority, problem, and station of each request
		// as well as compile a list of stations (used in conjunction with STATION_LIMIT)
		LinkedList<Emergency> emergencies = new LinkedList<Emergency>();
		HashMap<String, Integer> stations = new HashMap<String, Integer>();
		
		for (Request request : requests) {
			String message = request.getMessage();
			
			// Get the station
			String[] tokens = message.substring(1).split("\\b");
			String station = "";
			String lastToken = null;
			
			for (String token : tokens) {
				if (!". ".equals(lastToken) && token.length() > 1 && Character.isUpperCase(token.charAt(0))) {
					station += (station.length() != 0 ? " " : "") + token;
				}
				
				lastToken = token;
			}
			
			//if (!stations.containsKey(station)) {
			stations.put(station, 0);
			//}
			
			// Get the problem
			Problem problem = null;
			
			if (message.indexOf("tire") != -1 ||
				message.indexOf("car") != -1 ||
				message.indexOf("vehicle") != -1) {
				problem = Problem.VEHICLE;
			} else if (message.indexOf("air condition") != -1 ||
					   message.indexOf("power") != -1 ||
					   message.indexOf("leaking") != -1 ||
					   message.indexOf("window") != -1) {
				problem = Problem.FACILITY;
			} else if (message.indexOf("fever") != -1 ||
					   message.indexOf("breathing") != -1 ||
					   message.indexOf("passed out") != -1 ||
					   message.indexOf("seizure") != -1 ||
					   message.indexOf("broke") != -1 ||
					   message.indexOf("accident") != -1) {
				problem = Problem.MEDICAL;
			} else /*if (message.indexOf("marsquake") != -1 ||
					   message.indexOf("meteorite") != -1 ||
					   message.indexOf("dome") != -1)*/ {
				problem = Problem.ENVIRONMENT;
			}
			
			// Get the priority
			Priority priority = Priority.LOW;
			
			switch (problem) {
				case VEHICLE:
					if (message.indexOf("accident") != -1) {
						priority = Priority.HIGH;
					}
					break;
				case MEDICAL:
					if (message.indexOf("breathing") != -1 ||
						message.indexOf("seizure") != -1) {
						priority = Priority.HIGH;
					} else {
						priority = Priority.MEDIUM;
					}
					break;
				case ENVIRONMENT:
					priority = Priority.HIGH;
					break;
			}
			
			emergencies.add(new Emergency(priority, problem, station, request.getID()));
		}
		
		/* ---------------------------------------------------------------------------------- */
		
		// Process requests
		int lastCarry = 0;
		int totalRequests = requests.size();
		/*
		// TODO: make Emergency implement Comparable<Emergency> -- done
		TreeSet<Emergency> emergencyQueue = new TreeSet<Emergency>(new Comparator<Emergency>() {
			@Override
			public int compare(Emergency emergency1, Emergency emergency2) {
				int priority1 = emergency1.getPriority().getPriorityNumber();
				int id1 = emergency1.getID();
				
				int priority2 = emergency2.getPriority().getPriorityNumber();
				int id2 = emergency2.getID();
				
				int priorityDiff = priority1 - priority2;
				int idDiff = id1 - id2;
				return priorityDiff != 0 ? priorityDiff : idDiff;
			}
		});*/
		/*ArrayList<Emergency> emergencyQueue = new ArrayList<Emergency>();
		
		while (requestsCompleted < totalRequests) {
			//System.err.println();
			//System.err.println("======= Processing requests for day " + (days + 1));
			//System.err.println("======= " + lastCarry + " requests carried over from previous day");
			
			for (int i = 0; i < REQUESTS_PER_DAY && !emergencies.isEmpty(); i++) {
				emergencyQueue.add(emergencies.remove(0));
			}
			Collections.sort(emergencyQueue);
			
			int emergenciesRemoved = 0;
			
			for (int i = 0; i - emergenciesRemoved < emergencyQueue.size() && emergenciesRemoved < REQUESTS_PER_DAY; i++) {
				Emergency emergency = emergencyQueue.get(i - emergenciesRemoved);
				int stationUses = stations.get(emergency.getStation());
				
				if (stationUses < STATION_LIMIT || emergency.getPriority() == Priority.HIGH) {
					requestsCompleted++;
					emergenciesRemoved++;
					emergencyQueue.remove(emergency);
					stations.put(emergency.getStation(), stationUses + 1);
					
					//System.err.println("Dispatching " + emergency.getPriority() + " " + emergency.getProblem() + " responder to " + emergency.getStation());
				}
			}
			
			// Update carry stuff
			int carry = emergencyQueue.size();
			if (carry > largestCarry) {
				largestCarry = carry;
			}
			lastCarry = carry;
			averageCarry += carry;
			
			// Update other stuff
			stations.replaceAll((name, uses)->uses = 0);
			days++;
		}*/
		
		while (requestsCompleted < totalRequests) {
			//System.err.println();
			//System.err.println("======= Processing requests for day " + (days + 1));
			//System.err.println("======= " + lastCarry + " requests carried over from previous day");
			
			int emergenciesRemoved = dispatchEmergencies(REQUESTS_PER_DAY, STATION_LIMIT, totalRequests, lastCarry, 0, emergencies, stations, Priority.HIGH, true);
			emergenciesRemoved += dispatchEmergencies(REQUESTS_PER_DAY, STATION_LIMIT, totalRequests, lastCarry, emergenciesRemoved, emergencies, stations, Priority.MEDIUM, false);
			emergenciesRemoved += dispatchEmergencies(REQUESTS_PER_DAY, STATION_LIMIT, totalRequests, lastCarry, emergenciesRemoved, emergencies, stations, Priority.LOW, false);
			
			// Store relevant data
			// If I uncomment "+ lastCarry", it will take into account the requests from previous days
			// that were carried over, however for whatever reason, that halts the program somewhere
			// after the 6th simulation using "java RunSims large.txt 15 30 5 3 5"
			int carry = totalRequests != requestsCompleted ? REQUESTS_PER_DAY/* + lastCarry*/ - emergenciesRemoved : 0;
			if (carry > largestCarry) {
				largestCarry = carry;
			}
			
			// Reset for next day
			stations.replaceAll((name, uses)->uses = 0);
			days++;
			lastCarry = carry;
			averageCarry += carry;
		}
		
		averageCarry /= days;
	}
	
	private int dispatchEmergencies(final int REQUESTS_PER_DAY, final int STATION_LIMIT, int totalRequests, int carriedRequests, int previouslyRemoved, LinkedList<Emergency> emergencies, HashMap<String, Integer> stations, Priority priority, boolean force) {
		int emergenciesRemoved = 0;
		
		for (int i = 0; i < REQUESTS_PER_DAY + carriedRequests - previouslyRemoved && i - emergenciesRemoved < emergencies.size(); i++) {
			int emergencyIndex = i - emergenciesRemoved;
			Emergency emergency = emergencies.get(emergencyIndex);
			int stationUses = stations.get(emergency.getStation());
			
			if (emergency.getPriority() == priority && (stationUses < STATION_LIMIT || force)) {
				requestsCompleted++;
				emergencies.remove(emergencyIndex);
				emergenciesRemoved++;
				stations.put(emergency.getStation(), stationUses + 1);
				
				//System.err.println("Dispatching " + emergency.getPriority() + " " + emergency.getProblem() + " responder to " + emergency.getStation());
			}
		}
		
		return emergenciesRemoved;
	}
	
	public int getRequestsCompleted() {
		return requestsCompleted;
	}
	
	public int getDays() {
		return days;
	}
	
	public int getLargestCarry() {
		return largestCarry;
	}
	
	public int getAverageCarry() {
		return averageCarry;
	}
}
