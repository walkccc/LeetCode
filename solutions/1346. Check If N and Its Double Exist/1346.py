class Solution:
  def checkIfExist(self, arr: list[int]) -> bool:
    seen = set()

    for a in arr:
      if a * 2 in seen or a % 2 == 0 and a // 2 in seen:
        return True
      seen.add(a)

    return False
