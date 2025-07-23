class Solution {
  public int minDeletion(String s, int k) {
    Map<Character, Integer> count = new HashMap<>();

    for (final char c : s.toCharArray())
      count.merge(c, 1, Integer::sum);

    if (count.size() <= k)
      return 0;

    List<Integer> freqs = new ArrayList<>(count.values());
    Collections.sort(freqs);
    return freqs.subList(0, freqs.size() - k).stream().mapToInt(Integer::intValue).sum();
  }
}
