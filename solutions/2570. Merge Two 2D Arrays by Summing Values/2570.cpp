class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    constexpr int kMax = 1000;
    vector<vector<int>> ans;
    vector<int> count(kMax + 1);

    addCount(nums1, count);
    addCount(nums2, count);

    for (int i = 1; i <= kMax; ++i)
      if (count[i] > 0)
        ans.push_back({i, count[i]});

    return ans;
  }

 private:
  void addCount(const vector<vector<int>>& nums, vector<int>& count) {
    for (const vector<int>& idAndVal : nums) {
      const int id = idAndVal[0];
      const int val = idAndVal[1];
      count[id] += val;
    }
  }
};
