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
  public int getPermutationIndex(int[] perm) {
    final int kMod = 1_000_000_007;
    final int n = perm.length;
    int ans = 0;
    FenwickTree tree = new FenwickTree(n);
    int[] fact = new int[n + 1]; // fact[i] := i!
    Arrays.fill(fact, 1);

    for (int i = 2; i <= n; ++i)
      fact[i] = (int) ((fact[i - 1] * (long) i) % kMod);

    for (int i = 0; i < n; ++i) {
      final int num = perm[i];
      // the number of unused numbers less than `num`
      final int unusedNums = num - 1 - tree.get(num - 1);
      final int suffixLength = fact[n - 1 - i];
      ans = (int) ((ans + unusedNums * (long) suffixLength) % kMod);
      tree.add(num, 1);
    }

    return ans;
  }
}
