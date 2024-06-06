class Solution {
 public:
  int waysToPartition(vector<int>& nums, int k) {
    const int n = nums.size();
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    long prefix = 0;
    // count of sum(A[0..k)) - sum(A[k..n)) for k in [0..i)
    unordered_map<long, int> l;
    // count of sum(A[0..k)) - sum(A[k..n)) for k in [i..n)
    unordered_map<long, int> r;

    for (int pivot = 1; pivot < n; ++pivot) {
      prefix += nums[pivot - 1];
      const long suffix = sum - prefix;
      ++r[prefix - suffix];
    }

    int ans = r[0];
    prefix = 0;

    for (const int num : nums) {
      ans = max(ans, l[k - num] + r[num - k]);
      prefix += num;
      const long suffix = sum - prefix;
      const long diff = prefix - suffix;
      --r[diff];
      ++l[diff];
    }

    return ans;
  }
};
