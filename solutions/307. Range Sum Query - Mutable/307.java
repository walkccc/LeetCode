class FenwickTree {
  public FenwickTree(int n) {
    sums = new int[n + 1];
  }

  public void update(int i, int delta) {
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

class NumArray {
  public NumArray(int[] nums) {
    this.nums = nums;
    tree = new FenwickTree(nums.length);
    for (int i = 0; i < nums.length; ++i)
      tree.update(i + 1, nums[i]);
  }

  public void update(int index, int val) {
    tree.update(index + 1, val - nums[index]);
    nums[index] = val;
  }

  public int sumRange(int left, int right) {
    return tree.get(right + 1) - tree.get(left);
  }

  private int[] nums;
  private FenwickTree tree;
}
