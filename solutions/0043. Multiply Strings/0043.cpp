class Solution {
 public:
  string multiply(string num1, string num2) {
    string ans;
    vector<int> pos(num1.length() + num2.length());

    for (int i = num1.length() - 1; i >= 0; --i)
      for (int j = num2.length() - 1; j >= 0; --j) {
        const int multiply = (num1[i] - '0') * (num2[j] - '0');
        const int sum = multiply + pos[i + j + 1];
        pos[i + j] += sum / 10;
        pos[i + j + 1] = sum % 10;
      }

    for (const int p : pos)
      if (p > 0 || !ans.empty())
        ans += to_string(p);

    return ans.empty() ? "0" : ans;
  }
};