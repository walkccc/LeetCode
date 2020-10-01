class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    int prefixSum = 0;
    unordered_map<int, int> count{{0, 1}};  // {prefixSum: count}

    for (const int num : nums) {
      prefixSum += num;
      const int target = prefixSum - k;
      if (count.count(target))
        ans += count[target];
      ++count[prefixSum];
    }

    return ans;
  }
};