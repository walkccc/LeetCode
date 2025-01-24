class Solution:
  def maximumCoins(
      self,
      heroes: list[int],
      monsters: list[int],
      coins: list[int]
  ) -> list[int]:
    monsterAndCoins = sorted(list(zip(monsters, coins)))
    coinsPrefix = list(itertools.accumulate(
        (coin for _, coin in monsterAndCoins),
        initial=0))
    return [coinsPrefix[self._firstGreaterEqual(monsterAndCoins, hero)]
            for hero in heroes]

  def _firstGreaterEqual(
      self,
      monsterAndCoins: list[tuple[int, int]],
      hero: int,
  ) -> int:
    l, r = 0, len(monsterAndCoins)
    while l < r:
      m = (l + r) // 2
      if monsterAndCoins[m][0] > hero:
        r = m
      else:
        l = m + 1
    return l
