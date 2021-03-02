class NumArray {
  public NumArray(int[] nums) {
    this.nums = nums;
    tree = new FenwickTree(nums.length);
    for (int i = 0; i < nums.length; ++i)
      tree.update(i + 1, nums[i]);
  }

  public void update(int i, int val) {
    tree.update(i + 1, val - nums[i]);
    nums[i] = val;
  }

  public int sumRange(int i, int j) {
    return tree.get(j + 1) - tree.get(i);
  }

  private int[] nums;
  private FenwickTree tree;
}

class FenwickTree {
  public FenwickTree(int n) {
    sums = new int[n + 1];
  }

  public void update(int i, int delta) {
    while (i < sums.length) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  public int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

  private int[] sums;
}
