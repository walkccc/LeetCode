class Solution:
  def findNumOfValidWords(
      self,
      words: list[str],
      puzzles: list[str],
  ) -> list[int]:
    ans = []
    binaryCount = collections.Counter()

    for word in words:
      mask = 0
      for c in word:
        mask |= 1 << string.ascii_lowercase.index(c)
      binaryCount[mask] += 1

    for puzzle in puzzles:
      valid = 0
      n = len(puzzle) - 1
      for i in range(1 << n):
        mask = 1 << ord(puzzle[0]) - ord('a')
        for j in range(n):
          if i >> j & 1:
            mask |= 1 << ord(puzzle[j + 1]) - ord('a')
        if mask in binaryCount:
          valid += binaryCount[mask]
      ans.append(valid)

    return ans
