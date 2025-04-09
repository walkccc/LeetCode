class ValidWordAbbr {
  public ValidWordAbbr(String[] dictionary) {
    dict = new HashSet<>(Arrays.asList(dictionary));

    for (final String word : dict) {
      final String abbr = getAbbr(word);
      abbrUnique.put(abbr, !abbrUnique.containsKey(abbr));
    }
  }

  public boolean isUnique(String word) {
    final String abbr = getAbbr(word);
    final Boolean hasAbbr = abbrUnique.get(abbr);
    return hasAbbr == null || hasAbbr && dict.contains(word);
  }

  private Set<String> dict;
  private Map<String, Boolean> abbrUnique = new HashMap<>(); // T := unique, F := not unique

  private String getAbbr(final String s) {
    final int n = s.length();
    if (n <= 2)
      return s;
    return s.charAt(0) + Integer.toString(n - 2) + s.charAt(n - 1);
  }
}
