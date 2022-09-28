class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> ans;
    vector<vector<int>> bucket(n + 1);
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      bucket[freq].push_back(num);

    for (int freq = n; freq > 0; --freq) {
      for (const int num : bucket[freq])
        ans.push_back(num);
      if (ans.size() == k)
        return ans;
    }

    throw;
  }
};
