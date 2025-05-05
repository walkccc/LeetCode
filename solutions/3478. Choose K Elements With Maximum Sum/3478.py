class Solution:
  def findMaxSum(self, nums1: list[int], nums2: list[int], k: int) -> list[int]:
    ans = [0] * len(nums1)
    numAndIndexes = sorted([(num, i) for i, num in enumerate(nums1)])
    minHeap = []

    firstIndex = numAndIndexes[0][1]
    heapq.heappush(minHeap, nums2[firstIndex])
    summ = nums2[firstIndex]

    for (prevNum, prevIndex), (currNum, currIndex) in itertools.pairwise(numAndIndexes):
      if currNum == prevNum:
        ans[currIndex] = ans[prevIndex]
      else:
        ans[currIndex] = summ
      heapq.heappush(minHeap, nums2[currIndex])
      summ += nums2[currIndex]
      if len(minHeap) == k + 1:
        summ -= heapq.heappop(minHeap)

    return ans
