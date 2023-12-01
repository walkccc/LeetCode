class Solution:
  def largestInteger(self, num: int) -> int:
    s = str(num)
    ans = 0
    # maxHeap[0] := the odd digits
    # maxHeap[1] := the even digits
    maxHeap = [[] for _ in range(2)]

    for c in s:
      digit = ord(c) - ord('0')
      heapq.heappush(maxHeap[digit & 1], -digit)

    for c in s:
      i = ord(c) - ord('0') & 1
      ans = (ans * 10 - heapq.heappop(maxHeap[i]))

    return ans
