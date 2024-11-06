class Solution:
  def countDivisibleSubstrings(self, word: str) -> int:
    # Let f(c) = d, where d = 1, 2, ..., 9.
    # Rephrase the question to return the number of substrings that satisfy
    #    f(c1) + f(c2) + ... + f(ck) // k = avg
    # => f(c1) + f(c2) + ... + f(ck) - k * avg, where avg in [1, 9].
    ans = 0

    def f(c: str) -> int:
      return 9 - (ord('z') - ord(c)) // 3

    for avg in range(1, 10):
      prefix = 0
      prefixCount = collections.Counter({0: 1})
      for c in word:
        prefix += f(c) - avg
        ans += prefixCount[prefix]
        prefixCount[prefix] += 1

    return ans
