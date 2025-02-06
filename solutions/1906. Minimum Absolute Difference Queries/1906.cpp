class Solution {
 public:
  vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
    vector<vector<int>> numToIndices(101);

    for (int i = 0; i < nums.size(); ++i)
      numToIndices[nums[i]].push_back(i);

    if (numToIndices[nums[0]].size() == nums.size())
      return vector<int>(queries.size(), -1);

    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      int prevNum = -1;
      int minDiff = 101;
      for (int num = 1; num <= 100; ++num) {
        const auto& indices = numToIndices[num];
        const auto it = ranges::lower_bound(indices, l);
        if (it == indices.cend() || *it > r)
          continue;
        if (prevNum != -1)
          minDiff = min(minDiff, num - prevNum);
        prevNum = num;
      }
      ans.push_back(minDiff == 101 ? -1 : minDiff);
    }

    return ans;
  }
};
