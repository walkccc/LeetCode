class Solution:
  def maxDepthAfterSplit(self, seq: str) -> List[int]:
    ans = []
    depth = 1

    # Put all odd-depth parentheses in one group and even-depth parentheses in the other group.
    for c in seq:
      if c == '(':
        depth += 1
        ans.append(depth % 2)
      else:
        ans.append(depth % 2)
        depth -= 1

    return ans
