class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    vector<long long> ans(nums.size());
    unordered_map<int, vector<int>> numToIndices;

    for (int i = 0; i < nums.size(); ++i)
      numToIndices[nums[i]].push_back(i);

    for (const auto& [_, indices] : numToIndices) {
      const int n = indices.size();
      if (n == 1)
        continue;
      long long sumSoFar = accumulate(indices.begin(), indices.end(), 0LL);
      int prevIndex = 0;
      for (int i = 0; i < n; ++i) {
        sumSoFar += (i - 1) * (indices[i] - prevIndex);
        sumSoFar -= (n - i - 1) * (indices[i] - prevIndex);
        ans[indices[i]] = sumSoFar;
        prevIndex = indices[i];
      }
    }

    return ans;
  }
};
