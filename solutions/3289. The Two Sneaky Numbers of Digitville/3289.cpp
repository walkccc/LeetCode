class Solution {
 public:
  vector<int> getSneakyNumbers(const vector<int>& nums) {
    constexpr int kMax = 100;
    vector<int> ans;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      if (++count[num] == 2)
        ans.push_back(num);

    return ans;
  }
};
