class Solution:
  def canReorderDoubled(self, A: List[int]) -> bool:
    count = Counter(A)

    for key in sorted(count, key=abs):
      if count[key] > count[2 * key]:
        return False
      count[2 * key] -= count[key]

    return True
