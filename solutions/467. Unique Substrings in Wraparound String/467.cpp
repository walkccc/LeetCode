class Solution {
 public:
  int findSubstringInWraproundString(string s) {
    int maxLength = 1;
    // count[i] := the number of substrings ending in ('a' + i)
    vector<int> count(26);

    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25))
        ++maxLength;
      else
        maxLength = 1;
      const int index = s[i] - 'a';
      count[index] = max(count[index], maxLength);
    }

    return accumulate(count.begin(), count.end(), 0);
  }
};
