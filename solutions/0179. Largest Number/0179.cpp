class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    string ans;

    sort(begin(nums), end(nums), [](int a, int b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });

    for (const int num : nums)
      ans += to_string(num);

    return ans[0] == '0' ? "0" : ans;
  }
};
