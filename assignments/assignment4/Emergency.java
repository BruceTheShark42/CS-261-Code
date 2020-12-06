public class Emergency implements Comparable<Emergency> {
	private Priority priority;
	private Problem problem;
	private String station;
	private int id;
	
	public Emergency(Priority priority, Problem problem, String station, int id) {
		this.priority = priority;
		this.problem = problem;
		this.station = station;
		this.id = id;
	}
	
	public Priority getPriority() {
		return priority;
	}
	
	public Problem getProblem() {
		return problem;
	}
	
	public String getStation() {
		return station;
	}
	
	public int getID() {
		return id;
	}
	
	@Override
	public int compareTo(Emergency emergency) {
		int priorityDiff = priority.getPriorityNumber() - emergency.priority.getPriorityNumber();
		int idDiff = id - emergency.id;
		return priorityDiff != 0 ? priorityDiff : idDiff;
	}
}
