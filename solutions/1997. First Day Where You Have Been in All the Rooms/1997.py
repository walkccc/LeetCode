class Solution:
  def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(nextVisit)
    # dp[i] := the number of days to visit room i for the first time
    dp = [0] * n

    # Whenever we visit i, visit times of room[0..i - 1] are all even.
    # Therefore, the rooms before i can be seen as reset and we can safely
    # reuse dp[0..i - 1] as first-time visit to get second-time visit.
    for i in range(1, n):
      # The total days to visit room[i] is the sum of
      #   * dp[i - 1]: 1st-time visit room[i - 1]
      #   * 1: visit room[nextVisit[i - 1]]
      #   * dp[i - 1] - dp[nextVisit[i - 1]]: 2-time visit room[i - 1]
      #   * 1: visit room[i]
      dp[i] = (2 * dp[i - 1] - dp[nextVisit[i - 1]] + 2) % kMod

    return dp[-1]
