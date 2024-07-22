class Solution:
  def numberOfCombinations(self, num: str) -> int:
    if num[0] == '0':
      return 0

    kMod = 1_000_000_007
    n = len(num)
    # dp[i][k] := the number of possible lists of integers ending in num[i]
    # with the length of the last number being 1..k
    dp = [[0] * (n + 1) for _ in range(n)]
    # lcs[i][j] := the number of the same digits in num[i..n) and num[j..n)
    lcs = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
      for j in range(i + 1, n):
        if num[i] == num[j]:
          lcs[i][j] = lcs[i + 1][j + 1] + 1

    for i in range(n):
      for k in range(1, i + 2):
        dp[i][k] += dp[i][k - 1]
        dp[i][k] %= kMod
        # The last number is num[s..i].
        s = i - k + 1
        if num[s] == '0':
          # the number of possible lists of integers ending in num[i] with the
          # length of the last number being k
          continue
        if s == 0:  # the whole string
          dp[i][k] += 1
          continue
        if s < k:
          # The length k is not enough, so add the number of possible lists of
          # integers in num[0..s - 1].
          dp[i][k] += dp[s - 1][s]
          continue
        l = lcs[s - k][s]
        if l >= k or num[s - k + l] <= num[s + l]:
          # Have enough length k and num[s - k..s - 1] <= num[j..i].
          dp[i][k] += dp[s - 1][k]
        else:
          # Have enough length k but num[s - k..s - 1] > num[j..i].
          dp[i][k] += dp[s - 1][k - 1]

    return dp[n - 1][n] % kMod
