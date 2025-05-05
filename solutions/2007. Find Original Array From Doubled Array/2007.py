class Solution:
  def findOriginalArray(self, changed: list[int]) -> list[int]:
    ans = []
    q = collections.deque()

    for num in sorted(changed):
      if q and num == q[0]:
        q.popleft()
      else:
        q.append(num * 2)
        ans.append(num)

    return [] if q else ans
