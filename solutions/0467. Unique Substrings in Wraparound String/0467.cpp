class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    int maxLength = 1;
    vector<int> count(26);  // substrings end at i

    for (int i = 0; i < p.length(); ++i) {
      if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25))
        ++maxLength;
      else
        maxLength = 1;
      const int index = p[i] - 'a';
      count[index] = max(count[index], maxLength);
    }

    return accumulate(begin(count), end(count), 0);
  }
};
