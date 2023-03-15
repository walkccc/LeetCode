class Solution {
  public int getKth(int lo, int hi, int k) {
    int[][] powAndVals = new int[hi - lo + 1][2]; // (pow, val)

    for (int i = lo; i <= hi; ++i)
      powAndVals[i - lo] = new int[] {getPow(i), i};

    Arrays.sort(powAndVals, (a, b) -> a[0] - b[0]);
    return powAndVals[k - 1][1];
  }

  private int getPow(int n) {
    if (n == 1)
      return 0;
    return 1 + (n % 2 == 0 ? getPow(n / 2) : getPow(n * 3 + 1));
  }
}
