class Solution {
 public:
  string reformatNumber(string number) {
    string ans;

    std::erase(number, '-');
    std::erase(number, ' ');

    int i = 0;  // number's index
    for (i = 0; i + 4 < number.length(); i += 3)
      ans += number.substr(i, 3) + '-';

    const int countFinalDigits = number.length() - i;
    if (countFinalDigits < 4)
      ans += number.substr(i);
    else  // countFinalDigits == 4
      ans += number.substr(i, 2) + '-' + number.substr(i + 2);

    return ans;
  }
};
