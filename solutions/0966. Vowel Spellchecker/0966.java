class Solution {
  public String[] spellchecker(String[] wordlist, String[] queries) {
    List<String> ans = new ArrayList<>();
    Map<String, String> dict = new HashMap<>();

    for (final String word : wordlist) {
      dict.putIfAbsent(word, word);
      dict.putIfAbsent(lowerKey(word), word);
      dict.putIfAbsent(vowelKey(word), word);
    }

    for (final String query : queries)
      if (dict.containsKey(query))
        ans.add(dict.get(query));
      else if (dict.containsKey(lowerKey(query)))
        ans.add(dict.get(lowerKey(query)));
      else if (dict.containsKey(vowelKey(query)))
        ans.add(dict.get(vowelKey(query)));
      else
        ans.add("");

    return ans.toArray(new String[0]);
  }

  private String lowerKey(final String word) {
    return "$" + word.toLowerCase();
  }

  private String vowelKey(final String word) {
    StringBuilder sb = new StringBuilder();
    for (final char c : word.toCharArray())
      sb.append(isVowel(c) ? '*' : Character.toLowerCase(c));
    return sb.toString();
  }

  private boolean isVowel(char c) {
    return "aeiouAEIOU".indexOf(c) != -1;
  }
}
