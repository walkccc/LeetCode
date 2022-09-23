class Solution:
  def numMatchingSubseq(self, s: str, words: List[str]) -> int:
    ans = 0
    # pair (i, j) := words[i] and the character words[i][j] waiting fo
    bucket = [[] for _ in range(26)]

    # for each word, it's waiting for word[0]
    for i, word in enumerate(words):
      bucket[ord(word[0]) - ord('a')].append((i, 0))

    for c in s:
      # let prevBucket = bucket[c] and clear bucket[c]
      index = ord(c) - ord('a')
      prevBucket = bucket[index]
      bucket[index] = []
      for i, j in prevBucket:
        j += 1
        if j == len(words[i]):  # all characters in words[i] are matched
          ans += 1
        else:
          bucket[ord(words[i][j]) - ord('a')].append((i, j))

    return ans
