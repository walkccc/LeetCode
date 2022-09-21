class FenwickTree {
  public FenwickTree(int n) {
    this.n = n;
    sums = new int[2 * n + 1];
  }

  public void update(int i, int delta) {
    i += n + 1; // re-mapping
    while (i < sums.length) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  public int get(int i) {
    i += n + 1; // re-mapping
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

  private int n;
  private int[] sums;
}

class Solution {
  public int subarraysWithMoreZerosThanOnes(int[] nums) {
    final int kMod = 1_000_000_007;
    int ans = 0;
    int prefix = 0;
    FenwickTree tree = new FenwickTree(nums.length);
    tree.update(0, 1);

    for (final int num : nums) {
      prefix += num == 0 ? -1 : 1;
      ans += tree.get(prefix - 1);
      ans %= kMod;
      tree.update(prefix, 1);
    }

    return ans;
  }
}
