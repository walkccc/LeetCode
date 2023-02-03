/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *   public int guess(String word) {}
 * }
 */
class Solution {
  public void findSecretWord(String[] wordlist, Master master) {
    Random rand = new Random();

    for (int i = 0; i < 10; ++i) {
      final String guessedWord = wordlist[rand.nextInt(wordlist.length)];
      final int matches = master.guess(guessedWord);
      if (matches == 6)
        break;
      List<String> updated = new ArrayList<>();
      for (final String word : wordlist)
        if (getMatches(guessedWord, word) == matches)
          updated.add(word);
      wordlist = updated.toArray(new String[0]);
    }
  }

  private int getMatches(final String s1, final String s2) {
    int matches = 0;
    for (int i = 0; i < s1.length(); ++i)
      if (s1.charAt(i) == s2.charAt(i))
        ++matches;
    return matches;
  }
}
