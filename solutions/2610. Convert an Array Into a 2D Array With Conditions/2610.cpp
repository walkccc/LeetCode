class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    // The # of rows we need equals the max frequency.
    vector<vector<int>> ans;
    vector<int> count(nums.size() + 1);

    for (const int num : nums) {
      // Construct the `ans` on demand.
      if (++count[num] > ans.size())
        ans.push_back({});
      ans[count[num] - 1].push_back(num);
    }

    return ans;
  }
};
