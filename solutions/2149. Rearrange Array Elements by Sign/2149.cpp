class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans;
    vector<int> pos;
    vector<int> neg;

    for (const int num : nums)
      (num > 0 ? pos : neg).push_back(num);

    for (int i = 0; i < pos.size(); ++i) {
      ans.push_back(pos[i]);
      ans.push_back(neg[i]);
    }

    return ans;
  }
};
