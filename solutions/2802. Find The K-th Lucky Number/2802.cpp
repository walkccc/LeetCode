class Solution {
 public:
  string kthLuckyNumber(int k) {
    string ans;

    for (int i = k + 1; i > 0; i /= 2)
      ans += i % 2 == 0 ? '4' : '7';

    ranges::reverse(ans);
    return ans.substr(1);
  }
};
