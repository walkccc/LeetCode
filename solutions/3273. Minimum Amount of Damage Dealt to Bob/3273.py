from dataclasses import dataclass


@dataclass(frozen=True)
class Enemy:
  damage: int
  timeTakenDown: int


class Solution:
  def minDamage(self, power: int, damage: list[int], health: list[int]) -> int:
    ans = 0
    sumDamage = sum(damage)
    enemies = [Enemy(d, (h + power - 1) // power)
               for d, h in zip(damage, health)]

    # It's better to take down the enemy i first if the damage dealt of taking
    # down i first is less than the damage dealt of taking down j first. So,
    #    damage[i] * t[i] + (t[i] + t[j]) * damage[j] <
    #    damage[j] * t[j] + (t[i] + t[j]) * damage[i]
    # => damage[i] * t[i] + damage[j] * t[i] + damage[j] * t[j] <
    #    damage[j] * t[j] + damage[i] * t[j] + damage[i] * t[i]
    # => damage[j] * t[i] < damage[i] * t[j]
    # => damage[j] / t[j] < damage[i] / t[i]
    enemies.sort(key=lambda x: -x.damage / x.timeTakenDown)

    for enemy in enemies:
      ans += sumDamage * enemy.timeTakenDown
      sumDamage -= enemy.damage

    return ans
