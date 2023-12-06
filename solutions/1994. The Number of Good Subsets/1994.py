class Solution:
  def numberOfGoodSubsets(self, nums: List[int]) -> int:
    kMod = 1_000_000_007
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    n = 1 << len(primes)
    # dp[i] := the number of good subsets with set of primes = i bit mask
    dp = [1] + [0] * (n - 1)
    count = collections.Counter(nums)

    for num, freq in count.items():
      if num == 1:
        continue
      if any(num % squared == 0 for squared in [4, 9, 25]):
        continue
      numPrimesMask = sum(1 << i
                          for i, prime in enumerate(primes)
                          if num % prime == 0)
      for primesMask in range(n):
        # Skip since there're commen set of primes (becomes invalid subset)
        if primesMask & numPrimesMask > 0:
          continue
        nextPrimesMask = numPrimesMask | primesMask
        dp[nextPrimesMask] += dp[primesMask] * freq
        dp[nextPrimesMask] %= kMod

    return (1 << count[1]) * sum(dp[1:]) % kMod
