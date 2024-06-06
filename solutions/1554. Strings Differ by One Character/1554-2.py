class Solution:
  def differByOne(self, dict: List[str]) -> bool:
    kMod = 1_000_000_007
    m = len(dict[0])

    def val(c: str) -> int:
      return ord(c) - ord('a')

    def getHash(s: str) -> int:
      """Returns the hash of `s`. Assume the length of `s` is m.

      e.g. getHash(s) = 26^(m - 1) * s[0] + 26^(m - 2) * s[1] + ... + s[m - 1].
      """
      hash = 0
      for c in s:
        hash = (26 * hash + val(c))
      return hash

    wordToHash = [getHash(word) for word in dict]

    # Compute the hash without each letter.
    # e.g. hash of "abc" = 26^2 * 'a' + 26 * 'b' + 'c'
    #   newHash of "a*c" = hash - 26 * 'b'
    coefficient = 1
    for j in range(m - 1, -1, -1):
      newHashToIndices = collections.defaultdict(list)
      for i, (word, hash) in enumerate(zip(dict, wordToHash)):
        newHash = (hash - coefficient * val(word[j]) % kMod + kMod) % kMod
        if any(word[:j] == dict[index][:j] and word[j + 1:] == dict[index][j + 1:]
               for index in newHashToIndices[newHash]):
          return True
        newHashToIndices[newHash].append(i)
      coefficient = (26 * coefficient) % kMod

    return False
