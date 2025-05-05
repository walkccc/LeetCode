class Solution {
  public int racecar(int target) {
    int[] mem = new int[target + 1];
    Arrays.fill(mem, -1);
    return racecar(target, mem);
  }

  private int racecar(int i, int[] mem) {
    if (mem[i] >= 0)
      return mem[i];

    int res = Integer.MAX_VALUE;
    int x = 1;            // xA := (2^x - 1) unit distance
    int j = (1 << x) - 1; // j = 2^x - 1, k = 2^y - 1

    // (xA + 1R) + (yA + 1R) + racecar(i - (j - k))
    for (; j < i; j = (1 << ++x) - 1)
      for (int y = 0, k = 0; k < j; k = (1 << ++y) - 1)
        res = Math.min(res, (x + 1) + (y + 1) + racecar(i - (j - k), mem));

    // xA || (xA + 1R) + racecar(j - i)
    return mem[i] = Math.min(res, i == j ? x : x + 1 + racecar(j - i, mem));
  }
}
