class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    string ans;

    for (int i = shifts.size() - 2; i >= 0; --i)
      shifts[i] = (shifts[i] + shifts[i + 1]) % 26;

    for (int i = 0; i < s.length(); ++i)
      ans += (s[i] - 'a' + shifts[i]) % 26 + 'a';

    return ans;
  }
};
