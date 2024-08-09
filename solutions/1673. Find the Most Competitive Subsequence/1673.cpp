class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      // If |ans| - 1 + |nums[i..n)| >= k, then it means we still have enough
      // numbers, and we can safely pop an element from ans.
      while (!ans.empty() && ans.back() > nums[i] &&
             ans.size() - 1 + nums.size() - i >= k)
        ans.pop_back();
      if (ans.size() < k)
        ans.push_back(nums[i]);
    }

    return ans;
  }
};
