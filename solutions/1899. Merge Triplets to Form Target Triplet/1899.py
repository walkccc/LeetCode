class Solution:
  def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
    merged = [0] * len(target)

    for t in triplets:
      if all(a <= b for a, b in zip(t, target)):
        for i in range(3):
          merged[i] = max(merged[i], t[i])

    return merged == target
