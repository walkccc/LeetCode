class Solution:
  def strongPasswordChecker(self, password: str) -> int:
    n = len(password)
    missing = self._getMissing(password)
    # the number of replacements to deal with 3 repeating characters
    replaces = 0
    # the number of sequences that can be substituted with 1 deletions,
    # (3k)-seqs
    oneSeq = 0
    # the number of sequences that can be substituted with 2 deletions,
    # (3k + 1)-seqs
    twoSeq = 0

    i = 2
    while i < n:
      if password[i] == password[i - 1] and password[i - 1] == password[i - 2]:
        length = 2  # the length of the repeating password
        while i < n and password[i] == password[i - 1]:
          length += 1
          i += 1
        replaces += length // 3  # 'aaaaaaa' -> 'aaxaaxa'
        if length % 3 == 0:
          oneSeq += 1
        if length % 3 == 1:
          twoSeq += 1
      else:
        i += 1

    if n < 6:
      return max(6 - n, missing)
    if n <= 20:
      return max(replaces, missing)

    deletes = n - 20
    # Each replacement in (3k)-seqs can be substituted with 1 deletions.
    replaces -= min(oneSeq, deletes)
    # Each replacement in (3k + 1)-seqs can be substituted with 2 deletions.
    replaces -= min(max(deletes - oneSeq, 0), twoSeq * 2) // 2
    # Each replacement in other seqs can be substituted with 3 deletions.
    replaces -= max(deletes - oneSeq - twoSeq * 2, 0) // 3
    return deletes + max(replaces, missing)

  def _getMissing(self, password: str) -> int:
    return (3
            - any(c.isupper() for c in password)
            - any(c.islower() for c in password)
            - any(c.isdigit() for c in password))
