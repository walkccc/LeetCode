class Solution:
  def wateringPlants(self, plants: List[int], capacity: int) -> int:
    ans = 0
    currCapacity = 0

    for i, plant in enumerate(plants):
      if currCapacity + plant <= capacity:
        currCapacity += plant
      else:
        currCapacity = plant  # reset
        ans += i * 2

    return ans + len(plants)
