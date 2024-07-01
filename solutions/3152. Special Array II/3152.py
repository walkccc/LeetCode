class Solution:
  def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
    ans = []
    id = 0
    # parityIds[i] := the id of the parity group that nums[i] belongs to
    parityIds = [id]

    for i, (a, b) in enumerate(itertools.pairwise(nums)):
      # for i in range(1, len(nums)):
      if a % 2 == b % 2:
        id += 1
      parityIds.append(id)

    for _from, to in queries:
      ans.append(parityIds[_from] == parityIds[to])

    return ans
