class Solution:
  def isArraySpecial(
      self,
      nums: list[int],
      queries: list[list[int]],
  ) -> list[bool]:
    ans = []
    id = 0
    # parityIds[i] := the id of the parity group that nums[i] belongs to
    parityIds = [id]

    for a, b in itertools.pairwise(nums):
      if a % 2 == b % 2:
        id += 1
      parityIds.append(id)

    for _from, to in queries:
      ans.append(parityIds[_from] == parityIds[to])

    return ans
