class Solution {
  public int waysToMakeFair(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int[] even = new int[n + 1]; // the sum of even-indexed nums[0..i)
    int[] odd = new int[n + 1];  // the sum of odd-indexed nums[0..i)

    for (int i = 1; i <= n; ++i) {
      odd[i] = odd[i - 1];
      even[i] = even[i - 1];
      if (i % 2 == 0)
        even[i] += nums[i - 1];
      else
        odd[i] += nums[i - 1];
    }

    final int sum = even[n] + odd[n];

    for (int i = 0; i < n; ++i) {
      final int evenSum = even[i] + odd[n] - odd[i + 1];
      final int oddSum = sum - nums[i] - evenSum;
      if (evenSum == oddSum)
        ++ans;
    }

    return ans;
  }
}
