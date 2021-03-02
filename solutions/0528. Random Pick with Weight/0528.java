class Solution {
  public Solution(int[] w) {
    accumulated = w;
    for (int i = 1; i < accumulated.length; ++i)
      accumulated[i] += accumulated[i - 1];
  }

  public int pickIndex() {
    final int target = new Random().nextInt(accumulated[accumulated.length - 1]);
    int l = 0;
    int r = accumulated.length;

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (accumulated[m] > target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int[] accumulated;
}
