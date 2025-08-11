class Solution:
  def assignBikes(
      self,
      workers: list[list[int]],
      bikes: list[list[int]],
  ) -> list[int]:
    ans = [-1] * len(workers)
    usedBikes = [False] * len(bikes)
    # buckets[k] := (i, j), where k = dist(workers[i], bikes[j])
    buckets = [[] for _ in range(2001)]

    def dist(p1: list[int], p2: list[int]) -> int:
      return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    for i, worker in enumerate(workers):
      for j, bike in enumerate(bikes):
        buckets[dist(worker, bike)].append((i, j))

    for k in range(2001):
      for i, j in buckets[k]:
        if ans[i] == -1 and not usedBikes[j]:
          ans[i] = j
          usedBikes[j] = True

    return ans
