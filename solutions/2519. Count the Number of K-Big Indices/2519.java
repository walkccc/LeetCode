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
  public int kBigIndices(int[] nums, int k) {
    final int n = nums.length;
    int ans = 0;
    FenwickTree leftTree = new FenwickTree(n);
    FenwickTree rightTree = new FenwickTree(n);
    // left[i] := the number of `nums` < nums[i] with index < i
    int[] left = new int[n];
    // right[i] := the number of `nums` < nums[i] with index > i
    int[] right = new int[n];

    for (int i = 0; i < n; ++i) {
      left[i] = leftTree.get(nums[i] - 1);
      leftTree.add(nums[i], 1);
    }

    for (int i = n - 1; i >= 0; --i) {
      right[i] = rightTree.get(nums[i] - 1);
      rightTree.add(nums[i], 1);
    }

    for (int i = 0; i < n; ++i)
      if (left[i] >= k && right[i] >= k)
        ++ans;

    return ans;
  }
}
