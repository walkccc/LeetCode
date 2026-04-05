class Solution {
  public int[] minSubarraySort(int[] nums, int k) {
    final int n = nums.length;
    int[] ans = new int[n - k + 1];

    for (int i = 0; i <= n - k; ++i) {
      int[] window = Arrays.copyOfRange(nums, i, i + k);
      int[] sortedWindow = window.clone();
      Arrays.sort(sortedWindow);
      int l = 0;
      int r = k - 1;
      while (l < k && window[l] == sortedWindow[l])
        ++l;
      while (r >= 0 && window[r] == sortedWindow[r])
        --r;
      ans[i] = l > r ? 0 : r - l + 1;
    }

    return ans;
  }
}
