# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Sea(object):
#   def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#     pass
#
# class Point(object):
# def __init__(self, x: int, y: int):
# self.x = x
# self.y = y

class Solution(object):
  def countShips(
      self,
      sea: 'Sea',
      topRight: 'Point',
      bottomLeft: 'Point',
  ) -> int:
    if topRight.x < bottomLeft.x or topRight.y < bottomLeft.y:
      return 0
    if not sea.hasShips(topRight, bottomLeft):
      return 0

    # sea.hashShips(topRight, bottomLeft) == True
    if topRight.x == bottomLeft.x and topRight.y == bottomLeft.y:
      return 1

    mx = (topRight.x + bottomLeft.x) // 2
    my = (topRight.y + bottomLeft.y) // 2
    ans = 0
    # the top-right
    ans += self.countShips(sea, topRight, Point(mx + 1, my + 1))
    # the bottom-right
    ans += self.countShips(sea, Point(topRight.x, my),
                           Point(mx + 1, bottomLeft.y))
    # the top-left
    ans += self.countShips(sea, Point(mx, topRight.y),
                           Point(bottomLeft.x, my + 1))
    # the bottom-left
    ans += self.countShips(sea, Point(mx, my), bottomLeft)
    return ans
