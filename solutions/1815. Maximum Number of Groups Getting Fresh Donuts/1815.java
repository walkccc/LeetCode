class Solution {
  public int maxHappyGroups(int batchSize, int[] groups) {
    int happy = 0;
    int[] freq = new int[batchSize];

    for (int g : groups) {
      g %= batchSize;
      if (g == 0) {
        ++happy;
      } else if (freq[batchSize - g] > 0) {
        --freq[batchSize - g];
        ++happy;
      } else {
        ++freq[g];
      }
    }

    return happy + dp(freq, 0, batchSize);
  }

  private Map<String, Integer> mem = new HashMap<>();

  // Returns the maximum number of partitions can be formed.
  private int dp(int[] freq, int remainder, int batchSize) {
    final String hashed = hash(freq);
    if (mem.containsKey(hashed))
      return mem.get(hashed);

    int ans = 0;

    if (Arrays.stream(freq).anyMatch(f -> f != 0)) {
      for (int i = 0; i < freq.length; ++i)
        if (freq[i] > 0) {
          int[] newFreq = freq.clone();
          --newFreq[i];
          ans = Math.max(ans, dp(newFreq, (remainder + i) % batchSize, batchSize));
        }
      if (remainder == 0)
        ++ans;
    }

    mem.put(hash(freq), ans);
    return ans;
  }

  private String hash(int[] freq) {
    StringBuilder sb = new StringBuilder();
    for (final int f : freq)
      sb.append("#").append(f);
    return sb.toString();
  }
}
