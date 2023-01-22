class WordFilter {
  public WordFilter(String[] words) {
    for (int i = 0; i < words.length; ++i) {
      final String word = words[i];
      List<String> prefixes = new ArrayList<>();
      List<String> suffixes = new ArrayList<>();
      for (int j = 0; j <= word.length(); ++j) {
        final String prefix = word.substring(0, j);
        final String suffix = word.substring(j);
        prefixes.add(prefix);
        suffixes.add(suffix);
      }
      for (final String prefix : prefixes)
        for (final String suffix : suffixes)
          keyToIndex.put(prefix + '_' + suffix, i);
    }
  }

  public int f(String prefix, String suffix) {
    final String key = prefix + '_' + suffix;
    if (keyToIndex.containsKey(key))
      return keyToIndex.get(key);
    return -1;
  }

  private Map<String, Integer> keyToIndex = new HashMap<>();
}
