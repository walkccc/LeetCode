class Solution {
 public:
  vector<int> distinctNumbers(vector<int>& nums, int k) {
    vector<int> ans;
    int distinct = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < nums.size(); ++i) {
      if (++count[nums[i]] == 1)
        ++distinct;
      if (i >= k && --count[nums[i - k]] == 0)
        --distinct;
      if (i >= k - 1)
        ans.push_back(distinct);
    }

    return ans;
  }
};
