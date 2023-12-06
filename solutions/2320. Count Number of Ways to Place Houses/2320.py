class Solution:
  def countHousePlacements(self, n: int) -> int:
    kMod = 1_000_000_007
    house = 1  # the number of ways ending in a house
    space = 1  # the number of ways ending in a space
    total = house + space

    for _ in range(2, n + 1):
      house = space
      space = total
      total = (house + space) % kMod

    return total**2 % kMod
