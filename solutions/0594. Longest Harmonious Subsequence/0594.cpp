class Solution {
 public:
  int findLHS(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      if (count.count(num + 1))
        ans = max(ans, freq + count[num + 1]);

    return ans;
  }
};
