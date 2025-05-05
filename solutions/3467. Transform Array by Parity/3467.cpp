class Solution {
 public:
  vector<int> transformArray(vector<int>& nums) {
    vector<int> ans;
    vector<int> count(2);

    for (const int num : nums)
      ++count[num % 2];

    ans.insert(ans.end(), count[0], 0);
    ans.insert(ans.end(), count[1], 1);
    return ans;
  }
};
