class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;

    for (const int num : nums) {
      nums[abs(num) - 1] *= -1;
      if (nums[abs(num) - 1] > 0)
        ans.push_back(abs(num));
    }

    return ans;
  }
};