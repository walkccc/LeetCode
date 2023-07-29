class Solution {
  public boolean wordPattern(String pattern, String str) {
    String[] words = str.split(" ");
    if (words.length != pattern.length())
      return false;

    Map<Character, Integer> charToIndex = new HashMap<>();
    Map<String, Integer> stringToIndex = new HashMap<>();

    for (Integer i = 0; i < pattern.length(); ++i)
      if (charToIndex.put(pattern.charAt(i), i) != stringToIndex.put(words[i], i))
        return false;

    return true;
  }
}
