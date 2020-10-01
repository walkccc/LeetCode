class ValidWordAbbr {
  public ValidWordAbbr(String[] dictionary) {
    for (final String word : dictionary)
      if (word.length() > 2) {
        final String abbrev = getAbbrev(word);
        if (abbrevToWord.containsKey(abbrev)) {
          if (!abbrevToWord.get(abbrev).equals(word))
            abbrevToWord.put(abbrev, ""); // mark as "" (is not unique)
        } else {
          abbrevToWord.put(abbrev, word);
        }
      }
  }

  public boolean isUnique(String word) {
    if (word.length() <= 2)
      return true;

    final String abbrev = getAbbrev(word);
    return !abbrevToWord.containsKey(abbrev) || abbrevToWord.get(abbrev).equals(word);
  }

  private Map<String, String> abbrevToWord = new HashMap<>();

  private String getAbbrev(final String word) {
    final int innerLength = word.length() - 2;
    return word.charAt(0) + String.valueOf(innerLength) + word.charAt(word.length() - 1);
  }
}