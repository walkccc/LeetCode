class Solution:
  def decode(self, encoded: list[int], first: int) -> list[int]:
    ans = [first]

    for e in encoded:
      ans.append(e ^ ans[-1])

    return ans
