class Solution:
  def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> list[int]:
    if tomatoSlices % 2 == 1 or tomatoSlices < 2 * cheeseSlices or tomatoSlices > cheeseSlices * 4:
      return []

    jumboBurgers = (tomatoSlices - 2 * cheeseSlices) // 2

    return [jumboBurgers, cheeseSlices - jumboBurgers]
