class Solution:
  def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
    ans = []
    restaurantToIndex = {restaurant: i for i,
                         restaurant in enumerate(list1)}
    minSum = math.inf

    for i, restaurant in enumerate(list2):
      if restaurant in restaurantToIndex:
        summ = restaurantToIndex[restaurant] + i
        if summ < minSum:
          ans.clear()
        if summ <= minSum:
          ans.append(restaurant)
          minSum = summ

    return ans
