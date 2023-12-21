class Solution {
 public:
  int strongPasswordChecker(string s) {
    const int n = s.length();
    const int missing = getMissing(s);
    // the number of replacements to deal with 3 repeating characters
    int replaces = 0;
    // the number of sequences that can be substituted with 1 deletions,
    // (3k)-seqs
    int oneSeq = 0;
    // the number of sequences that can be substituted with 2 deletions,
    // (3k + 1)-seqs
    int twoSeq = 0;

    for (int i = 2; i < n;)
      if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
        int length = 2;  // the length of the repeating s
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
    // Each replacement in (3k)-seqs can be substituted with 1 deletions.
    replaces -= min(oneSeq, deletes);
    // Each replacement in (3k + 1)-seqs can be substituted with 2 deletions.
    replaces -= min(max(deletes - oneSeq, 0), twoSeq * 2) / 2;
    // Each replacement in other seqs can be substituted with 3 deletions.
    replaces -= max(deletes - oneSeq - twoSeq * 2, 0) / 3;
    return deletes + max(replaces, missing);
  }

 private:
  int getMissing(const string& s) {
    int missing = 3;
    if (ranges::any_of(s, [](char c) { return isupper(c); }))
      --missing;
    if (ranges::any_of(s, [](char c) { return islower(c); }))
      --missing;
    if (ranges::any_of(s, [](char c) { return isdigit(c); }))
      --missing;
    return missing;
  }
};
