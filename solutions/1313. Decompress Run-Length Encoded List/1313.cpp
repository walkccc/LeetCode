class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i += 2)
      ans.insert(end(ans), nums[i], nums[i + 1]);

    return ans;
  }
};
