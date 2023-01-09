class Solution {
 public:
  string largestMultipleOfThree(vector<int>& digits) {
    string ans;
    vector<int> mod1{1, 4, 7, 2, 5, 8};
    vector<int> mod2{2, 5, 8, 1, 4, 7};
    vector<int> count(10);
    int sum = accumulate(begin(digits), end(digits), 0);

    for (int digit : digits) ++count[digit];

    while (sum % 3 != 0)
      for (int i : sum % 3 == 1 ? mod1 : mod2)
        if (count[i]) {
          --count[i];
          sum -= i;
          break;
        }

    for (int digit = 9; digit >= 0; --digit)
      ans += string(count[digit], '0' + digit);

    return ans.size() && ans[0] == '0' ? "0" : ans;
  }
};
