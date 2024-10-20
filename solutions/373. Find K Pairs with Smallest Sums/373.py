class Solution:
  def kSmallestPairs(self, nums1: list[int],
                     nums2: list[int],
                     k: int) -> list[list[int]]:
    minHeap = []

    for i in range(min(k, len(nums1))):
      heapq.heappush(minHeap, (nums1[i] + nums2[0], i, 0))

    ans = []
    while minHeap and len(ans) < k:
      _, i, j = heapq.heappop(minHeap)
      ans.append([nums1[i], nums2[j]])
      if j + 1 < len(nums2):
        heapq.heappush(minHeap, (nums1[i] + nums2[j + 1], i, j + 1))

    return ans
