class Solution {
 public:
  // Same as 3254. Find the Power of K-Size Subarrays I
  vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> ans;
    int start = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] != nums[i - 1] + 1)
        start = i;
      if (i >= k - 1)
        ans.push_back(i - start + 1 >= k ? nums[i] : -1);
    }

    return ans;
  }
};
