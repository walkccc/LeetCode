from dataclasses import dataclass


@dataclass
class Player:
  age: int
  score: int


class Solution:
  def bestTeamScore(self, scores: list[int], ages: list[int]) -> int:
    n = len(scores)
    players = [Player(age, score) for age, score in zip(ages, scores)]
    # dp[i] := the maximum score of choosing the players[0..i] with the
    # players[i] being selected
    dp = [0] * n

    # Sort by age descending, then by score descending
    players.sort(key=lambda x: (-x.age, -x.score))

    for i in range(n):
      # For each player, choose it first
      dp[i] = players[i].score
      # players[j].age >= players[i].age since we sort in descending order.
      # So, we only have to check that players[j].score >= players[i].score.
      for j in range(i):
        if players[j].score >= players[i].score:
          dp[i] = max(dp[i], dp[j] + players[i].score)

    return max(dp)
