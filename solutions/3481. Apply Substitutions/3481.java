class Solution {
  public String applySubstitutions(List<List<String>> replacements, String text) {
    Map<String, String> replaceMap = new HashMap<>();

    for (List<String> replacement : replacements) {
      final String key = replacement.get(0);
      final String value = replacement.get(1);
      replaceMap.put(key, value);
    }

    return evaluate(text, replaceMap);
  }

  // Evaluates the `text` and replaces the placeholders with the values
  // from the `replaceMap` recursively.
  private String evaluate(final String text, Map<String, String> replaceMap) {
    StringBuilder sb = new StringBuilder();
    int i = 0;
    while (i < text.length())
      if (text.charAt(i) == '%') {
        final int j = i + 1 + text.substring(i + 1).indexOf('%');
        final String key = text.substring(i + 1, j);
        final String value = replaceMap.get(key);
        sb.append(evaluate(value, replaceMap));
        i = j + 1;
      } else {
        sb.append(text.charAt(i++));
      }
    return sb.toString();
  }
}
