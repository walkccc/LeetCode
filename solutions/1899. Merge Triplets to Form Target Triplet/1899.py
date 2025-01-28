class Solution:
  def mergeTriplets(self, triplets: list[list[int]], target: list[int]) -> bool:
    merged = [0] * len(target)

    for triplet in triplets:
      if all(a <= b for a, b in zip(triplet, target)):
        for i in range(3):
          merged[i] = max(merged[i], triplet[i])

    return merged == target
