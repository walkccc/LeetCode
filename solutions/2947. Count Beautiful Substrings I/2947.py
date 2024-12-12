class Solution:
  def beautifulSubstrings(self, s: str, k: int) -> int:
    kVowels = 'aeiou'
    root = self._getRoot(k)
    ans = 0
    vowels = 0
    vowelsMinusConsonants = 0
    # {(vowels, vowelsMinusConsonants): count}
    prefixCount = collections.Counter({(0, 0): 1})

    for c in s:
      if c in kVowels:
        vowelsMinusConsonants += 1
        vowels = (vowels + 1) % root
      else:
        vowelsMinusConsonants -= 1
      ans += prefixCount[(vowels, vowelsMinusConsonants)]
      prefixCount[(vowels, vowelsMinusConsonants)] += 1

    return ans

  def _getRoot(self, k: int) -> int:
    for i in range(1, k + 1):
      if i * i % k == 0:
        return i
