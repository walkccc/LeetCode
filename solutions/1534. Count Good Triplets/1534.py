class Solution:
  def countGoodTriplets(self, arr: list[int], a: int, b: int, c: int) -> int:
    return sum(abs(arr[i] - arr[j]) <= a and
               abs(arr[j] - arr[k]) <= b and
               abs(arr[i] - arr[k]) <= c
               for i, j, k in itertools.combinations(range(len(arr)), 3))
