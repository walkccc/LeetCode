class Solution {
 public:
  vector<int> orArray(vector<int>& nums) {
    vector<int> ans;
    for (int i = 1; i < nums.size(); ++i)
      ans.push_back(nums[i - 1] | nums[i]);
    return ans;
  }
};
