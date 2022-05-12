class Solution {
 public:
  int strongPasswordChecker(string s) {
    const int n = s.length();
    const int missing = getMissing(s);
    // # of replacements to deal with 3 repeating characters
    int replaces = 0;
    // # of seqs that can be substituted with 1 deletions, (3k)-seqs
    int oneSeq = 0;
    // # of seqs that can be substituted with 2 deletions, (3k + 1)-seqs
    int twoSeq = 0;

    for (int i = 2; i < n;)
      if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
        int length = 2;  // length of repeating s
        while (i < n && s[i] == s[i - 1]) {
          ++length;
          ++i;
        }
        replaces += length / 3;  // 'aaaaaaa' -> 'aaxaaxa'
        if (length % 3 == 0)
          ++oneSeq;
        if (length % 3 == 1)
          ++twoSeq;
      } else {
        ++i;
      }

    if (n < 6)
      return max(6 - n, missing);
    if (n <= 20)
      return max(replaces, missing);

    const int deletes = n - 20;
    // each replacement in (3k)-seqs can be substituted with 1 deletions
    replaces -= min(oneSeq, deletes);
    // each replacement in (3k + 1)-seqs can be substituted with 2 deletions
    replaces -= min(max(deletes - oneSeq, 0), twoSeq * 2) / 2;
    // each replacement in other seqs can be substituted with 3 deletions
    replaces -= max(deletes - oneSeq - twoSeq * 2, 0) / 3;
    return deletes + max(replaces, missing);
  }

 private:
  int getMissing(const string& s) {
    int missing = 3;
    if (any_of(begin(s), end(s), [](char c) { return isupper(c); }))
      --missing;
    if (any_of(begin(s), end(s), [](char c) { return islower(c); }))
      --missing;
    if (any_of(begin(s), end(s), [](char c) { return isdigit(c); }))
      --missing;
    return missing;
  }
};
