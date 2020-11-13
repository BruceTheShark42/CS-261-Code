import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Set;
import java.util.Map;
import java.util.Iterator;
import java.util.Comparator;
import java.util.TreeSet;
import java.util.NavigableSet;

public class ReadLines {
	private final static int MIN_SEQUENCE_LENGTH = 5;
	private final static int MAX_SEQUENCE_LENGTH = 15;
	private final static int POSSIBLE_SEQUENCE_LENGTHS = MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1;
	
	public static void main(String[] args) {
		if (args.length == 1) {
			ArrayList<String> lines = new ArrayList<String>();
			
			try {
				Scanner scanner = new Scanner(new File(args[0]));
				while (scanner.hasNextLine()) {
					lines.add(scanner.nextLine());
				}
				scanner.close();
				
				// Now that all the lines have been read,
				// check them for subsequences.
				
				// Since all lines must have the subsequence for it to
				// be considered a subsequence, just check the first line.
				String line0 = lines.get(0);
				
				// This automatically handles duplicate subsequences
				HashSet<String> possibleSubsequences = new HashSet<String>();
				
				for (int i = MIN_SEQUENCE_LENGTH; i <= MAX_SEQUENCE_LENGTH; i++) {
					for (int j = 0; j < line0.length() - i + 1; j++) {
						possibleSubsequences.add(line0.substring(j, j + i));
					}
				}
				
				// Now that all the possible subsequences have been obtained,
				// check each line to see if it has that sequence, and if
				// every line does have it, it's a valid subsequence.
				
				// subsequence, # of occurances
				HashMap<String, Integer> subsequences = new HashMap<String, Integer>();
				
				// Start from the second line because
				// the first one was already checked.
				for (int i = 1; i < lines.size(); i++) {
					String line = lines.get(i);
					
					// Check the line for each subsequence
					// If the line has the subsequence more than once,
					// it doesn't matter because it only needs to be there once.
					for (String subsequence : possibleSubsequences) {
						int index = line.indexOf(subsequence);
						
						// If the index is valid
						if (index != -1) {
							if (subsequences.containsKey(subsequence)) {
								subsequences.replace(subsequence, subsequences.get(subsequence) + 1);
							} else {
								subsequences.put(subsequence, 1);
							}
						}
					}
				}
				
				Set<Map.Entry<String, Integer>> validSet = subsequences.entrySet();
				Iterator<Map.Entry<String, Integer>> validIt = validSet.iterator();
				
				ArrayList<String> validSubsequences = new ArrayList<String>();
				
				while (validIt.hasNext()) {
					Map.Entry<String, Integer> entry = validIt.next();
					if (lines.size() - 1 == entry.getValue()) {
						validSubsequences.add(entry.getKey());
					}
				}
				
				validSubsequences.sort(new Comparator<String>() {
					@Override
					public int compare(String string1, String string2) {
						int lengthDifference = string2.length() - string1.length();
						return lengthDifference != 0 ? lengthDifference : string1.compareTo(string2);
					}
				});
				
				TreeSet<Integer> invalidIndices = new TreeSet<Integer>();
				
				for (int i = 0; i < validSubsequences.size(); i++) {
					String subsequence1 = validSubsequences.get(i);
					for (int j = 0; j < validSubsequences.size(); j++) {
						if (i != j) {
							String subsequence2 = validSubsequences.get(j);
							if (subsequence1.contains(subsequence2)) {
								invalidIndices.add(j);
							} else if (subsequence2.contains(subsequence1)) {
								invalidIndices.add(i);
							}
						}
					}
				}
				
				NavigableSet<Integer> reversedIndices = invalidIndices.descendingSet();
				for (Iterator<Integer> it = reversedIndices.iterator(); it.hasNext();) {
					validSubsequences.remove(it.next().intValue());
				}
				
				System.out.println("Found the following DNA sequences in all strands:");
				for (String subsequence : validSubsequences) {
					System.out.println(subsequence);
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
		} else {
			System.err.println("Usage: java ReadLines <FileName>");
		}
	}
}
