class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> count{{0, 1}};  // {prefix sum: count}

    for (const int num : nums) {
      prefix += num;
      const int target = prefix - k;
      if (count.count(target))
        ans += count[target];
      ++count[prefix];
    }

    return ans;
  }
};
