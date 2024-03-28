class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ans;
    int curr = 0;

    for (const int num : nums) {
      curr = (curr * 2 + num) % 5;
      ans.push_back(curr % 5 == 0);
    }

    return ans;
  }
};
