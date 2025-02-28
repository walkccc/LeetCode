class Solution {
 public:
  string largestGoodInteger(string num) {
    string ans;

    for (int i = 2; i < num.length(); ++i)
      if (num[i - 2] == num[i - 1] && num[i - 1] == num[i])
        ans = max(ans, num.substr(i - 2, 3));

    return ans;
  }
};
