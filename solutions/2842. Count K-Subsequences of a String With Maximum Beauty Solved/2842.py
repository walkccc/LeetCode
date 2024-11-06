class Solution:
  def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:
    kMod = 1_000_000_007
    count = collections.Counter(s)
    if len(count) < k:
      return 0

    ans = 1
    # freqCount := (f(c), # of chars with f(c))
    freqCount = collections.Counter(count.values())

    for fc, numOfChars in list(sorted(freqCount.items(), reverse=True)):
      if numOfChars >= k:
        ans *= math.comb(numOfChars, k) * pow(fc, k, kMod)
        return ans % kMod
      ans *= pow(fc, numOfChars, kMod)
      ans %= kMod
      k -= numOfChars
