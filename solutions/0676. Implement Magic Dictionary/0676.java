class MagicDictionary {
  public void buildDict(String[] dict) {
    for (final String word : dict)
      for (int i = 0; i < word.length(); ++i) {
        String modifiedWord = word.substring(0, i) + '*' + word.substring(i + 1, word.length());
        if (!map.containsKey(modifiedWord))
          map.put(modifiedWord, word.charAt(i));
        else if (map.get(modifiedWord) != word.charAt(i))
          map.put(modifiedWord, '*');
      }
  }

  public boolean search(String word) {
    for (int i = 0; i < word.length(); ++i) {
      String modifiedWord = word.substring(0, i) + '*' + word.substring(i + 1, word.length());
      if (map.containsKey(modifiedWord) && map.get(modifiedWord) != word.charAt(i))
        return true;
    }

    return false;
  }

  private Map<String, Character> map = new HashMap<>();
}