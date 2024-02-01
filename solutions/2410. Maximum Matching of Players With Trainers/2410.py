class Solution:
  def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
    ans = 0

    players.sort()
    trainers.sort()

    for i, trainer in enumerate(trainers):
      if players[ans] <= trainers[i]:
        ans += 1
        if ans == len(players):
          return ans

    return ans
  

