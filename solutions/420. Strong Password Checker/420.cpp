class Solution {
 public:
  int strongPasswordChecker(string password) {
    const int n = password.length();
    const int missing = getMissing(password);
    // the number of replacements to deal with 3 repeating characters
    int replaces = 0;
    // the number of sequences that can be substituted with 1 deletions,
    // (3k)-seqs
    int oneSeq = 0;
    // the number of sequences that can be substituted with 2 deletions,
    // (3k + 1)-seqs
    int twoSeq = 0;

    for (int i = 2; i < n;)
      if (password[i] == password[i - 1] &&
          password[i - 1] == password[i - 2]) {
        int length = 2;  // the length of the repeating password
        while (i < n && password[i] == password[i - 1]) {
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
  int getMissing(const string& password) {
    return 3 -  //
           ranges::any_of(password, [](char c) { return isupper(c); }) -
           ranges::any_of(password, [](char c) { return islower(c); }) -
           ranges::any_of(password, [](char c) { return isdigit(c); });
  }
};
