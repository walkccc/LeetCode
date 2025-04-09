class Solution {
  public boolean reportSpam(String[] message, String[] bannedWords) {
    Set<String> bannedWordsSet = new HashSet<>(Arrays.asList(bannedWords));
    int count = 0;

    for (final String word : message)
      if (bannedWordsSet.contains(word) && ++count > 1)
        return true;

    return false;
  }
}
