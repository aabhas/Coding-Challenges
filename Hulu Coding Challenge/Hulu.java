import java.net.*;
import java.io.*;
import com.json.parsers.*;
import java.util.*;

public class Hulu {

	private static List dict = new ArrayList<String>();

	public static void main(String[] args) throws Exception {

		System.out.println("===========================");
		System.out.println("========= NEW GAME ========");
		System.out.println("===========================");

		// Loading the dictionary

		Scanner s = new Scanner(new File("enable1.txt"));
		while (s.hasNext()) {
			dict.add(s.next());
		}
		s.close();

		// Already guessed charachter's list

		List<String> usedChars = new ArrayList<String>();

		String newURL = "http://gallows.hulu.com/play?code=asharm36@illinois.edu";
		URL oracle = new URL(newURL);

		while (oracle != null) {

			BufferedReader in = new BufferedReader(new InputStreamReader(
					oracle.openStream()));
			String jsonTxt;
			jsonTxt = in.readLine();
			in.close();

			JsonParserFactory factory = JsonParserFactory.getInstance();
			JSONParser parser = factory.newJsonParser();
			Map jsonMap = parser.parseJson(jsonTxt);

			long token = Long.parseLong(jsonMap.get("token") + "");
			int remaining_guesses = Integer.parseInt(jsonMap
					.get("remaining_guesses") + "");
			String status = jsonMap.get("status") + "";
			String state = jsonMap.get("state") + "";

			System.out.println("token: " + token);
			System.out.println("remaining_guesses: " + remaining_guesses);
			System.out.println("status: " + status);
			System.out.println("state: " + state);

			if (status.equalsIgnoreCase("ALIVE")) {

				/*
				 * Testing using completely random
				 * 
				 * Random r = new Random(); char c = (char) (r.nextInt(26) +
				 * 'a'); String newGuess = c + "";
				 */

				// Searching for the new guess

				String newGuess = nextGuess(state, usedChars) + "";

				System.out.println(" -------- Let's guess ------- " + newGuess);
				newURL = "http://gallows.hulu.com/play?code=asharm36@illinois.edu&token="
						+ token + "&guess=" + newGuess;
				oracle = new URL(newURL);
			} else {
				oracle = null;
				System.out.println("The HUMAN is : " + status);
				System.out.println("===========================");
				System.out.println("========= END GAME ========");
				System.out.println("===========================");
			}
		}
	}

	public static char nextGuess(String state, List<String> usedChars) {

		String letterGuessed = "";
		String[] words = state.split(" ");
		boolean doRandom = true; // If the all the words are empty then do
									// random.
		String possibleChars[] = {};

		for (String word : words) {
			String[] letters = word.split("(?!^)");
			String regexStr = "";

			for (String letter : letters) {
				if (!letter.equalsIgnoreCase("_")) {
					doRandom = false;

					// Build the regex string for searching dictionary
					regexStr += letter.toLowerCase();

				} else {
					regexStr += "[a-z]";
				}
			}
			/*
			 * 
				Search Dictionary using the regex string. Idea of search is to go
				through each of the 170,000+ elemets in the dictionary and check
				if each of the string matches our current regex. If so the we
				split its characters and merge these characters to the existing
				possible character set. Later on we randomly choose one of the 
				letter in this possible character set keeping in mind that we 
				not guessing the same number again.
				
				This is a naive algorithm that we have used due to time constraints.
				The following straight forward enhancements can be done but currently
				not there:
				1. Guess the really small words which are mostly conjunctions first.
				   This can be done for 2-4 letter words and can be made fast by keeping
				   another static set of possible conjunctions in english.
				2. Definitely right now the search is done linearly for the whole file.
				   We can trivially split this file into files containing words of a fixed
				   length making search space decrease.
				3. Right now we search all the words but we should keep a set which decreases
				   on each iteration by removing all the words from the previously searched 
				   words which did not satisfy the last guess attempt i.e. which contain a
				   letter which just made a failed guess. Thus, decreasing the search space
				   further. 
				4. Definitely, going for further rigorous data structures like trees and 
				   dictionary is always a never ending game. 
				   
			Right now our time is linear to the number of words in dictionary i.e. order of 
			170 K +.
			
			*
			*
			*/
			
			

			if (!doRandom) {
				Iterator<String> iter = dict.iterator();

				while (iter.hasNext()) {
					String nextStr = iter.next();
					if (nextStr.matches(regexStr)) {
						possibleChars = Hulu.merge(possibleChars,
								nextStr.split("(?!^)"));
					}
				}
			}
		}

		if (doRandom) {
			// Randomly select any letter as all the words are empty in this
			// case

			Random r = new Random();
			char c = (char) (r.nextInt(26) + 'a');
			return c;

		} else {
			// If some letters are given, randomly pick from the list of
			// possible letters prepared above but do check if the guess was
			// made before or not.

			System.out.println("Possible Letters  :"
					+ Arrays.toString(possibleChars));

			while (true) {
				Random r = new Random();
				int randInt = r.nextInt(possibleChars.length);
				if (usedChars.contains(possibleChars[randInt])) {
					// Make sure we are not repeating our guess.
					continue;
				} else {
					// Storing in the already guessed set.
					letterGuessed = possibleChars[randInt];
					usedChars.add(letterGuessed);
					break;
				}
			}
		}

		// Should never execute !!
		Random r = new Random();
		char c = (char) (r.nextInt(26) + 'a');
		return c;
	}

	public static String[] merge(String[] a, String[] b) {
		List<String> lst = new ArrayList<String>(Arrays.asList(a));
		lst.addAll(Arrays.asList(b));

		Set<String> set = new HashSet<String>(lst);
		ArrayList<String> mergeListWithoutDuplicates = new ArrayList<String>();
		mergeListWithoutDuplicates.addAll(set);

		String[] result = mergeListWithoutDuplicates.toArray(new String[set
				.size()]);
		Arrays.sort(result);
		// System.out.println("Merged output result is" +
		// Arrays.toString(result));

		return result;
	}
}