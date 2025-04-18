class Solution:
  def maxAverageRatio(
      self,
      classes: list[list[int]],
      extraStudents: int,
  ) -> float:
    def extraPassRatio(pas: int, total: int) -> float:
      """Returns the extra pass ratio if a brilliant student joins."""
      return (pas + 1) / (total + 1) - pas / total

    maxHeap = [(-extraPassRatio(pas, total), pas, total)
               for pas, total in classes]
    heapq.heapify(maxHeap)

    for _ in range(extraStudents):
      _, pas, total = heapq.heappop(maxHeap)
      heapq.heappush(
          maxHeap, (-extraPassRatio(pas + 1, total + 1), pas + 1, total + 1))

    return sum(pas / total for _, pas, total in maxHeap) / len(maxHeap)
