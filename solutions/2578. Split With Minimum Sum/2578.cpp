class Solution {
 public:
  int splitNum(int num) {
    string num1;
    string num2;
    string s = to_string(num);

    ranges::sort(s);

    for (int i = 0; i < s.length(); ++i)
      if (i % 2 == 0)
        num1 += s[i];
      else
        num2 += s[i];

    return stoi(num1) + stoi(num2);
  }
};
