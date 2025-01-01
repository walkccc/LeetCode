class Solution {
  public Solution(int[] w) {
    prefix = w;
    for (int i = 1; i < prefix.length; ++i)
      prefix[i] += prefix[i - 1];
  }

  public int pickIndex() {
    final int target = rand.nextInt(prefix[prefix.length - 1]);
    int l = 0;
    int r = prefix.length;

    while (l < r) {
      final int m = (l + r) / 2;
      if (prefix[m] > target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int[] prefix;
  private Random rand = new Random();
}
