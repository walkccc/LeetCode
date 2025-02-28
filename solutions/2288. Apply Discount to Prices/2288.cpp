class Solution {
 public:
  string discountPrices(string sentence, int discount) {
    constexpr int kPrecision = 2;
    string ans;
    istringstream iss(sentence);

    for (string word; iss >> word;)
      if (word[0] == '$' && word.length() > 1) {
        const string digits = word.substr(1);
        if (ranges::all_of(digits,
                           [](const char digit) { return isdigit(digit); })) {
          const double val = stold(digits) * (100 - discount) / 100;
          const string s = to_string(val);
          const string trimmed = s.substr(0, s.find(".") + kPrecision + 1);
          ans += "$" + trimmed + " ";
        } else {
          ans += word + " ";
        }
      } else {
        ans += word + " ";
      }

    ans.pop_back();
    return ans;
  }
};
