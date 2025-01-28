class Solution {
  public String frequencySort(String s) {
    final int n = s.length();
    StringBuilder sb = new StringBuilder();
    int[] count = new int[128];
    // buckets[i] := characters that appear i times in s
    List<Character>[] buckets = new List[n + 1];

    for (final char c : s.toCharArray())
      ++count[c];

    for (int i = 0; i < 128; ++i) {
      final int freq = count[i];
      if (freq > 0) {
        if (buckets[freq] == null)
          buckets[freq] = new ArrayList<>();
        buckets[freq].add((char) i);
      }
    }

    for (int freq = n; freq > 0; --freq)
      if (buckets[freq] != null)
        for (final char c : buckets[freq])
          for (int i = 0; i < freq; ++i)
            sb.append(c);

    return sb.toString();
  }
}
