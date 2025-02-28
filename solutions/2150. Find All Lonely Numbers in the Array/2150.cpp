class Solution {
 public:
  vector<int> findLonely(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      if (freq == 1 && !count.contains(num - 1) && !count.contains(num + 1))
        ans.push_back(num);

    return ans;
  }
};
