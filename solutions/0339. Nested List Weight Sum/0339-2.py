class Solution:
  def depthSum(self, nestedList: List[NestedInteger]) -> int:
    ans = 0

    def dfs(nestedList: List[NestedInteger], depth: int) -> None:
      nonlocal ans
      for ni in nestedList:
        if ni.isInteger():
          ans += ni.getInteger() * depth
        else:
          dfs(ni.getList(), depth + 1)

    dfs(nestedList, 1)
    return ans
