class Solution {
  public boolean isAlienSorted(String[] words, String order) {
    for (int i = 0; i < order.length(); ++i)
      map.put(order.charAt(i), (char) (i + 'a'));

    for (int i = 0; i + 1 < words.length; ++i)
      if (bigger(words[i], words[i + 1]))
        return false;

    return true;
  }

  private Map<Character, Character> map = new HashMap<>();

  private boolean bigger(String s1, String s2) {
    for (int i = 0; i < s1.length() && i < s2.length(); ++i)
      if (s1.charAt(i) != s2.charAt(i))
        return map.get(s1.charAt(i)) > map.get(s2.charAt(i));

    return s1.length() > s2.length();
  }
}