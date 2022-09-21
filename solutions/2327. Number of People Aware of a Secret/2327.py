class Solution:
  def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
    kMod = 1_000_000_007
    share = 0
    # dp[i] := # of people know the secret at day i
    dp = [0] * n  # map day i to i + 1
    dp[0] = 1

    for i in range(1, n):
      if i - delay >= 0:
        share += dp[i - delay]
      if i - forget >= 0:
        share -= dp[i - forget]
      share += kMod
      share %= kMod
      dp[i] = share

    # people before day `n - forget - 1` already forget the secret
    return sum(dp[-forget:]) % kMod
