class Solution {
  public int minimumDeletions(int[] nums) {
    final int n = nums.length;

    int mn = Integer.MAX_VALUE;
    int mx = Integer.MIN_VALUE;
    int minIndex = -1;
    int maxIndex = -1;

    for (int i = 0; i < n; ++i) {
      if (nums[i] < mn) {
        mn = nums[i];
        minIndex = i;
      }
      if (nums[i] > mx) {
        mx = nums[i];
        maxIndex = i;
      }
    }

    final int a = Math.min(minIndex, maxIndex);
    final int b = Math.max(minIndex, maxIndex);

    // min(delete from front and back,
    //     delete from front,
    //     delete from back)
    return Math.min(a + 1 + n - b, Math.min(b + 1, n - a));
  }
}
