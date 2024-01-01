class MagicDictionary {
  public void buildDict(String[] dictionary) {
    for (final String word : dictionary)
      for (int i = 0; i < word.length(); ++i) {
        final String replaced = getReplaced(word, i);
        dict.put(replaced, dict.containsKey(replaced) ? '*' : word.charAt(i));
      }
  }

  public boolean search(String searchWord) {
    for (int i = 0; i < searchWord.length(); ++i) {
      final String replaced = getReplaced(searchWord, i);
      if (dict.getOrDefault(replaced, searchWord.charAt(i)) != searchWord.charAt(i))
        return true;
    }
    return false;
  }

  private Map<String, Character> dict = new HashMap<>();

  private String getReplaced(final String s, int i) {
    return s.substring(0, i) + '*' + s.substring(i + 1);
  }
}
