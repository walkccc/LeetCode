class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> seen{begin(nums), end(nums)};

    for (long num : nums)
      // the start num of a sequence
      if (!seen.count(num - 1)) {
        int length = 0;
        while (seen.count(num++))
          ++length;
        ans = max(ans, length);
      }

    return ans;
  }
};
