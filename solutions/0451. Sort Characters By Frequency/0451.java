class Solution {
  public String frequencySort(String s) {
    final int n = s.length();
    StringBuilder sb = new StringBuilder();
    int[] count = new int[128];
    // bucket[i] := stores chars that appear i times in s
    List<Character>[] bucket = new List[n + 1];

    for (final char c : s.toCharArray())
      ++count[c];

    for (int i = 0; i < 128; ++i) {
      final int freq = count[i];
      if (freq > 0) {
        if (bucket[freq] == null)
          bucket[freq] = new ArrayList<>();
        bucket[freq].add((char) i);
      }
    }

    for (int freq = n; freq > 0; --freq)
      if (bucket[freq] != null)
        for (final char c : bucket[freq])
          for (int i = 0; i < freq; ++i)
            sb.append(c);

    return sb.toString();
  }
}
