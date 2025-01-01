class Solution {
  public String stoneGameIII(int[] stoneValue) {
    int[] mem = new int[stoneValue.length];
    Arrays.fill(mem, Integer.MIN_VALUE);
    final int score = stoneGameIII(stoneValue, 0, mem);
    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }

  // Returns the maximum relative score Alice can make from stoneValue[i..n).
  private int stoneGameIII(int[] stoneValue, int i, int[] mem) {
    if (i == stoneValue.length)
      return 0;
    if (mem[i] > Integer.MIN_VALUE)
      return mem[i];

    int sum = 0;
    for (int j = i; j < i + 3 && j < stoneValue.length; ++j) {
      sum += stoneValue[j];
      mem[i] = Math.max(mem[i], sum - stoneGameIII(stoneValue, j + 1, mem));
    }

    return mem[i];
  };
}
