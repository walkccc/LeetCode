class Solution {
 public:
  int maxDiff(int num) {
    const string s = to_string(num);
    int firstNot9 = s.find_first_not_of('9');
    int firstNot01 = s.find_first_not_of("01");
    if (firstNot9 == string::npos)
      firstNot9 = 0;
    if (firstNot01 == string::npos)
      firstNot01 = 0;

    string a = s;
    string b = s;
    replace(a.begin(), a.end(), s[firstNot9], '9');
    replace(b.begin(), b.end(), s[firstNot01], firstNot01 == 0 ? '1' : '0');
    return stoi(a) - stoi(b);
  }
};
