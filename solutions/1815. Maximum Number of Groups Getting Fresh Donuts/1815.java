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

  private Map<String, Integer> memo = new HashMap<>();

  private int dp(int[] freq, int r, int batchSize) {
    final String hashed = hash(freq);
    if (memo.containsKey(hashed))
      return memo.get(hashed);

    int ans = 0;

    if (Arrays.stream(freq).anyMatch(f -> f != 0)) {
      for (int i = 0; i < freq.length; ++i)
        if (freq[i] > 0) {
          int[] newFreq = freq.clone();
          --newFreq[i];
          ans = Math.max(ans, dp(newFreq, (r + i) % batchSize, batchSize));
        }
      if (r == 0)
        ++ans;
    }

    memo.put(hash(freq), ans);
    return ans;
  }

  private String hash(int[] freq) {
    StringBuilder sb = new StringBuilder();
    for (final int f : freq)
      sb.append("#").append(f);
    return sb.toString();
  }
}
