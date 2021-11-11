class Solution:
  def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
    restaurants.sort(key=lambda r: (-r[1], -r[0]))
    return [i for i, _, v, p, d in restaurants if v >= veganFriendly and p <= maxPrice and d <= maxDistance]
