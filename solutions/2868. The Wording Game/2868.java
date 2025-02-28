class Solution {
  public boolean canAliceWin(String[] a, String[] b) {
    // words[0][i] := the biggest word starting with ('a' + i) for Alice
    // words[1][i] := the biggest word starting with ('a' + i) for Bob
    String[][] words = new String[2][26];

    // For each letter, only the biggest word is useful.
    for (final String word : a)
      words[0][word.charAt(0) - 'a'] = word;

    for (final String word : b)
      words[1][word.charAt(0) - 'a'] = word;

    // Find Alice's smallest word.
    int i = 0;
    while (words[0][i] == null)
      ++i;

    // Iterate through each letter until we find a winner.
    // Start with Alice's turn (0), so it's Bob's turn (1) now.
    for (int turn = 1; true; turn = turn ^ 1)
      // If the current player has a word that having the letter that is greater
      // than the opponent's word, choose it.
      if (words[turn][i] != null && words[turn][i].compareTo(words[1 - turn][i]) > 0) {
        // Choose the current words[turn][i].
      } else if (words[turn][i + 1] != null) {
        // Choose the next words[turn][i + 1].
        ++i;
      } else {
        // Game over. If it's Bob's turn, Alice wins, and vice versa.
        return turn == 1;
      }
  }
}
