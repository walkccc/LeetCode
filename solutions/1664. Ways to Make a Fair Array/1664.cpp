class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    vector<int> even(n + 1);  // the sum of even-indexed nums[0..i)
    vector<int> odd(n + 1);   // the sum of odd-indexed nums[0..i)

    for (int i = 1; i <= n; ++i) {
      odd[i] = odd[i - 1];
      even[i] = even[i - 1];
      if (i % 2 == 0)
        even[i] += nums[i - 1];
      else
        odd[i] += nums[i - 1];
    }

    const int sum = even.back() + odd.back();

    for (int i = 0; i < n; ++i) {
      const int evenSum = even[i] + odd.back() - odd[i + 1];
      const int oddSum = sum - nums[i] - evenSum;
      if (evenSum == oddSum)
        ++ans;
    }

    return ans;
  }
};
