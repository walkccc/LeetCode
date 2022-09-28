class FenwickTree:
  def __init__(self, n: int):
    self.sums = [0] * (n + 1)

  def update(self, i: int, delta: int) -> None:
    while i < len(self.sums):
      self.sums[i] += delta
      i += self._lowbit(i)

  def get(self, i: int) -> int:
    summ = 0
    while i > 0:
      summ += self.sums[i]
      i -= self._lowbit(i)
    return summ

  def _lowbit(self, i) -> int:
    return i & -i


class Solution:
  def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
    n = len(nums1)
    numToIndex = {num: i for i, num in enumerate(nums1)}
    # Remap each num in nums2 to the according index in nums1 as A
    # Then, rephrase the problem as finding increasing tripets in A
    A = [numToIndex[num] for num in nums2]
    # leftSmaller[i] := # of A[j] < A[i], where 0 <= j < i
    leftSmaller = [0] * n
    # rightLarger[i] := # of A[j] > A[i], where i < j < n
    rightLarger = [0] * n
    tree1 = FenwickTree(n)  # to calculate leftSmaller
    tree2 = FenwickTree(n)  # to calculate rightLarger

    for i, a in enumerate(A):
      leftSmaller[i] = tree1.get(a)
      tree1.update(a + 1, 1)

    for i, a in reversed(list(enumerate(A))):
      rightLarger[i] = tree2.get(n) - tree2.get(a)
      tree2.update(a + 1, 1)

    return sum(a * b for a, b in zip(leftSmaller, rightLarger))
