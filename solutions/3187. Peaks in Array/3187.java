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
  public List<Integer> countOfPeaks(int[] nums, int[][] queries) {
    List<Integer> ans = new ArrayList<>();
    int[] peak = getPeak(nums);
    FenwickTree tree = new FenwickTree(peak.length);

    for (int i = 0; i < peak.length; ++i)
      tree.add(i + 1, peak[i]);

    // Update the peak array and Fenwick tree if the peak status of nums[i]
    // changes.
    for (int[] query : queries) {
      if (query[0] == 1) {
        final int l = query[1];
        final int r = query[2];
        ans.add(r - l < 2 ? 0 : tree.get(r) - tree.get(l + 1));
      } else if (query[0] == 2) {
        final int index = query[1];
        final int val = query[2];
        nums[index] = val;
        update(nums, peak, tree, index);
        if (index > 0)
          update(nums, peak, tree, index - 1);
        if (index + 1 < nums.length)
          update(nums, peak, tree, index + 1);
      }
    }

    return ans;
  }

  private void update(int[] nums, int[] peak, FenwickTree tree, int i) {
    final int newPeak = isPeak(nums, i) ? 1 : 0;
    if (newPeak != peak[i]) {
      tree.add(i + 1, newPeak - peak[i]);
      peak[i] = newPeak;
    }
  }

  private int[] getPeak(int[] nums) {
    int[] peak = new int[nums.length];
    for (int i = 1; i + 1 < nums.length; i++)
      peak[i] = nums[i] > nums[i - 1] && nums[i] > nums[i + 1] ? 1 : 0;
    return peak;
  }

  private boolean isPeak(int[] nums, int i) {
    return i > 0 && i + 1 < nums.length && nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
  }
}
