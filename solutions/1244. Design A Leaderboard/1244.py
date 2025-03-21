class Leaderboard:
  def __init__(self):
    self.idToScore = collections.Counter()

  def addScore(self, playerId: int, score: int) -> None:
    self.idToScore[playerId] += score

  def top(self, K: int) -> int:
    return sum(score for _, score in self.idToScore.most_common(K))

  def reset(self, playerId: int) -> None:
    del self.idToScore[playerId]
