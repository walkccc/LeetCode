class Solution:
  def isWinner(self, player1: list[int], player2: list[int]) -> int:
    def getScore(player: list[int]) -> int:
      kInvalid = -3
      score = 0
      last10 = kInvalid
      for i, p in enumerate(player):
        score += p if i - last10 > 2 else p * 2
        if p == 10:
          last10 = i
      return score

    score1 = getScore(player1)
    score2 = getScore(player2)
    if score1 > score2:
      return 1
    if score2 > score1:
      return 2
    return 0
