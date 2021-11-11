class Solution {
  public String[] spellchecker(String[] wordlist, String[] queries) {
    List<String> ans = new ArrayList<>();
    Map<String, String> dict = new HashMap<>();

    for (final String word : wordlist) {
      dict.putIfAbsent(word, word);
      dict.putIfAbsent(lowerKey(word), word);
      dict.putIfAbsent(vowelKey(word), word);
    }

    for (final String q : queries)
      if (dict.containsKey(q))
        ans.add(dict.get(q));
      else if (dict.containsKey(lowerKey(q)))
        ans.add(dict.get(lowerKey(q)));
      else if (dict.containsKey(vowelKey(q)))
        ans.add(dict.get(vowelKey(q)));
      else
        ans.add("");

    return ans.toArray(new String[0]);
  }

  private String lowerKey(final String word) {
    return "$" + word.toLowerCase();
  }

  private String vowelKey(final String word) {
    String s = "";
    for (char c : word.toCharArray())
      s += isVowel(c) ? '*' : Character.toLowerCase(c);
    return s;
  }

  private boolean isVowel(char c) {
    c = Character.toLowerCase(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
}
