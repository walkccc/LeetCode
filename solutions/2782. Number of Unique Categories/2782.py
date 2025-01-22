# Definition for a category handler.
# class CategoryHandler:
#   def haveSameCategory(self, a: int, b: int) -> bool:
#     pass

class Solution:
  def numberOfCategories(
      self,
      n: int,
      categoryHandler: Optional['CategoryHandler'],
  ) -> int:
    ans = 0

    for i in range(n):
      if not any(categoryHandler.haveSameCategory(i, j) for j in range(i)):
        ans += 1

    return ans
