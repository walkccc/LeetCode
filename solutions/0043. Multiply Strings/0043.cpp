class Solution {
 public:
  string multiply(string num1, string num2) {
    string s(num1.length() + num2.length(), '0');

    for (int i = num1.length() - 1; i >= 0; --i)
      for (int j = num2.length() - 1; j >= 0; --j) {
        const int mult = (num1[i] - '0') * (num2[j] - '0');
        const int sum = mult + (s[i + j + 1] - '0');
        s[i + j] += sum / 10;
        s[i + j + 1] = '0' + sum % 10;
      }

    const int i = s.find_first_not_of('0');
    return i == -1 ? "0" : s.substr(i);
  }
};
