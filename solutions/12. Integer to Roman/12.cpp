class Solution {
 public:
  string intToRoman(int num) {
    const vector<pair<int, string>> valueSymbols{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};
    string ans;

    for (const auto& [value, symbol] : valueSymbols) {
      if (num == 0)
        break;
      while (num >= value) {
        num -= value;
        ans += symbol;
      }
    }

    return ans;
  }
};
