class Solution:
  def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
    ans = []
    restaurantToIndex = {restaurant: i for i,
                         restaurant in enumerate(list1)}
    minSum = inf

    for i, restaurant in enumerate(list2):
      if restaurant in restaurantToIndex:
        sum = restaurantToIndex[restaurant] + i
        if sum < minSum:
          ans.clear()
        if sum <= minSum:
          ans.append(restaurant)
          minSum = sum

    return ans
