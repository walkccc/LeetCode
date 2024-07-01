class LargerStrKey(str):
  def __lt__(x: str, y: str) -> bool:
    return x + y > y + x


class Solution:
  def largestNumber(self, nums: List[int]) -> str:
    return ''.join(sorted(map(str, nums), key=LargerStrKey)).lstrip('0') or '0'
