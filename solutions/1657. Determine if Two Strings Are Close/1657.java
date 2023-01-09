class Solution {
  public boolean closeStrings(String word1, String word2) {
    if (word1.length() != word2.length())
      return false;

    Map<Character, Integer> count1 = new HashMap<>();
    Map<Character, Integer> count2 = new HashMap<>();

    for (final char c : word1.toCharArray())
      count1.put(c, count1.getOrDefault(c, 0) + 1);

    for (final char c : word2.toCharArray())
      count2.put(c, count2.getOrDefault(c, 0) + 1);

    if (!count1.keySet().equals(count2.keySet()))
      return false;

    List<Integer> freqs1 = new ArrayList<>(count1.values());
    List<Integer> freqs2 = new ArrayList<>(count2.values());

    Collections.sort(freqs1);
    Collections.sort(freqs2);

    return freqs1.equals(freqs2);
  }
}
