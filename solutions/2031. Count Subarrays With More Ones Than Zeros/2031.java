class FenwickTree {
  public FenwickTree(int n) {
    sums = new int[n + 1];
  }

  public void add(int i, int delta) {
    while (i < sums.length) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  public int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

  private int[] sums;

  private static int lowbit(int i) {
    return i & -i;
  }
}

class Solution {
  public int subarraysWithMoreZerosThanOnes(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    int ans = 0;
    int prefix = 0;
    FenwickTree tree = new FenwickTree(2 * n + 1);
    tree.add(remap(0, n), 1);

    for (final int num : nums) {
      prefix += num == 0 ? -1 : 1;
      ans += tree.get(remap(prefix - 1, n));
      ans %= kMod;
      tree.add(remap(prefix, n), 1);
    }

    return ans;
  }

  private int remap(int i, int n) {
    return i + n + 1;
  }
}
