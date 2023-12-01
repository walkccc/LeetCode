class Solution {
  public int strongPasswordChecker(String s) {
    final int n = s.length();
    final char[] chars = s.toCharArray();
    final int missing = getMissing(chars);
    // the number of replacements to deal with 3 repeating characters
    int replaces = 0;
    // the number of sequences that can be substituted with 1 deletions, (3k)-seqs
    int oneSeq = 0;
    // the number of sequences that can be substituted with 2 deletions, (3k + 1)-seqs
    int twoSeq = 0;

    for (int i = 2; i < n;)
      if (chars[i] == chars[i - 1] && chars[i - 1] == chars[i - 2]) {
        int length = 2; // Length of repeating chars
        while (i < n && chars[i] == chars[i - 1]) {
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

  private int getMissing(final char[] chars) {
    int missing = 3;

    for (final char c : chars)
      if (Character.isUpperCase(c)) {
        --missing;
        break;
      }

    for (final char c : chars)
      if (Character.isLowerCase(c)) {
        --missing;
        break;
      }

    for (final char c : chars)
      if (Character.isDigit(c)) {
        --missing;
        break;
      }

    return missing;
  }
}
