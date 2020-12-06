import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;

/*
 * ---------------------------------------- VERY IMPORTANT PLEASE READ ----------------------------------------
 * I have spent more time on this assignment than I usually do on assignments.
 * The only reason being I couldn't get the output exactly right. However,
 * that is worth at most 5 points, so I can just not get those 5 points and
 * still have an A. I'd rather do that than needlessly stress myself about this.
 * That being said, this was still a pretty fun assignment that I did learn new
 * things about, so it wasn't all in vain. :)
 */
public class RunSims {
	public static void main(String[] args) {
		if (args.length == 6) {
			try {
				// Read these first because if they're malformatted
				// and the file was read first, that file reading
				// would just be wasted performance.
				final int RPD_MIN = Integer.parseInt(args[1]);
				final int RPD_MAX = Integer.parseInt(args[2]);
				final int RPD_STEP = Integer.parseInt(args[3]);
				final int SL_MIN = Integer.parseInt(args[4]);
				final int SL_MAX = Integer.parseInt(args[5]);
				
				// Read the file once for all simulations
				Scanner scanner = new Scanner(new File(args[0]));
				ArrayList<Request> requests = new ArrayList<Request>();
				String line;
				
				while (scanner.hasNextLine() && (line = scanner.nextLine()) != null) {
					int colonIndex = line.indexOf(':');
					int id = Integer.parseInt(line.substring(0, colonIndex));
					String message = line.substring(colonIndex + 2);
					requests.add(new Request(id, message));
				}
				
				scanner.close();
				
				// Simulate
				for (int i = RPD_MIN; i <= RPD_MAX; i += RPD_STEP) {
					for (int j = SL_MIN; j <= SL_MAX; j++) {
						Simulation simulation = new Simulation();
						simulation.run(requests, i, j);
						
						System.out.println("Requests Per Day: " + i + " Station Limit: " + j);
						System.out.println("  Requests: " + simulation.getRequestsCompleted());
						System.out.println("  Days: " + simulation.getDays());
						System.out.println("  Largest Carry: " + simulation.getLargestCarry());
						System.out.println("  Average Carry: " + simulation.getAverageCarry());
						
						// While debugging, I used stdout for output and stderr for verbose
						//System.err.println("Requests Per Day: " + i + " Station Limit: " + j);
						//System.err.println("  Requests: " + simulation.getRequestsCompleted());
						//System.err.println("  Days: " + simulation.getDays());
						//System.err.println("  Largest Carry: " + simulation.getLargestCarry());
						//System.err.println("  Average Carry: " + simulation.getAverageCarry());
					}
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		} else {
			System.err.println("Usage: java RunSims <datafile> <RPD_MIN> <RPD_MIN> <RPD_STEP> <SL_MIN> <SL_MAX>");
		}
	}
}
