class Solution {
  public boolean canConvert(String str1, String str2) {
    if (str1.equals(str2))
      return true;

    Map<Character, Character> mappings = new HashMap<>();

    for (int i = 0; i < str1.length(); ++i) {
      final char a = str1.charAt(i);
      final char b = str2.charAt(i);
      if (mappings.getOrDefault(a, b) != b)
        return false;
      mappings.put(a, b);
    }

    // No letter in the str1 maps to > 1 letter in the str2 and there is at
    // lest one temporary letter can break any loops.
    return new HashSet<>(mappings.values()).size() < 26;
  }
}
