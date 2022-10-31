class Solution:
  def depthSum(self, nestedList: List[NestedInteger]) -> int:
    ans = 0
    depth = 0
    q = deque()

    def addIntegers(nestedList: List[NestedInteger]) -> None:
      for ni in nestedList:
        q.append(ni)

    addIntegers(nestedList)

    while q:
      depth += 1
      for _ in range(len(q)):
        ni = q.popleft()
        if ni.isInteger():
          ans += ni.getInteger() * depth
        else:
          addIntegers(ni.getList())

    return ans
