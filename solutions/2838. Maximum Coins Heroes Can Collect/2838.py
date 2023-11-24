class Solution:
  def maximumCoins(self, heroes: List[int], monsters: List[int], coins: List[int]) -> List[int]:
    monsterAndCoins = sorted(list(zip(monsters, coins)))
    coinsPrefix = [0] + \
        list(itertools.accumulate(coin for _, coin in monsterAndCoins))
    return [coinsPrefix[self._firstGreaterEqual(monsterAndCoins, hero)] for hero in heroes]

  def _firstGreaterEqual(self, monsterAndCoins: List[tuple[int, int]], hero: int) -> int:
    l, r = 0, len(monsterAndCoins)
    while l < r:
      m = (l + r) // 2
      if monsterAndCoins[m][0] > hero:
        r = m
      else:
        l = m + 1
    return l
