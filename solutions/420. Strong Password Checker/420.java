class Solution {
  public int strongPasswordChecker(String password) {
    final int n = password.length();
    final int missing = getMissing(password);
    // the number of replacements to deal with 3 repeating characters
    int replaces = 0;
    // the number of sequences that can be substituted with 1 deletions, (3k)-seqs
    int oneSeq = 0;
    // the number of sequences that can be substituted with 2 deletions, (3k + 1)-seqs
    int twoSeq = 0;

    for (int i = 2; i < n;)
      if (password.charAt(i) == password.charAt(i - 1) &&
          password.charAt(i - 1) == password.charAt(i - 2)) {
        int length = 2; // the length of the repeating password
        while (i < n && password.charAt(i) == password.charAt(i - 1)) {
          ++length;
          ++i;
        }
        replaces += length / 3; // 'aaaaaaa' -> 'aaxaaxa'
        if (length % 3 == 0)
          ++oneSeq;
        if (length % 3 == 1)
          ++twoSeq;
      } else {
        ++i;
      }

    if (n < 6)
      return Math.max(6 - n, missing);
    if (n <= 20)
      return Math.max(replaces, missing);

    final int deletes = n - 20;
    // Each replacement in (3k)-seqs can be substituted with 1 deletions.
    replaces -= Math.min(oneSeq, deletes);
    // Each replacement in (3k + 1)-seqs can be substituted with 2 deletions.
    replaces -= Math.min(Math.max(deletes - oneSeq, 0), twoSeq * 2) / 2;
    // Each replacement in other seqs can be substituted with 3 deletions.
    replaces -= Math.max(deletes - oneSeq - twoSeq * 2, 0) / 3;
    return deletes + Math.max(replaces, missing);
  }

  private int getMissing(final String password) {
    return 3 - //
        (password.chars().anyMatch(Character::isUpperCase) ? 1 : 0) -
        (password.chars().anyMatch(Character::isLowerCase) ? 1 : 0) -
        (password.chars().anyMatch(Character::isDigit) ? 1 : 0);
  }
}
