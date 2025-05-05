class Solution:
  def depthSumInverse(self, nestedList: list[NestedInteger]) -> int:
    ans = 0
    prevSum = 0
    q = collections.deque(nestedList)

    while q:
      for _ in range(len(q)):
        ni = q.popleft()
        if ni.isInteger():
          prevSum += ni.getInteger()
        else:
          for nextNi in ni.getList():
            q.append(nextNi)
      ans += prevSum

    return ans
