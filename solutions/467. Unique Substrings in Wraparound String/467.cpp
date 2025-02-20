class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    int maxLength = 1;
    // count[i] := the number of substrings ending in ('a' + i)
    vector<int> count(26);

    for (int i = 0; i < p.length(); ++i) {
      if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25))
        ++maxLength;
      else
        maxLength = 1;
      const int index = p[i] - 'a';
      count[index] = max(count[index], maxLength);
    }

    return accumulate(count.begin(), count.end(), 0);
  }
};
