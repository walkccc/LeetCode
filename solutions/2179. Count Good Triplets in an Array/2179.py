class FenwickTree:
  def __init__(self, n: int):
    self.sums = [0] * (n + 1)

  def add(self, i: int, delta: int) -> None:
    while i < len(self.sums):
      self.sums[i] += delta
      i += FenwickTree.lowbit(i)

  def get(self, i: int) -> int:
    summ = 0
    while i > 0:
      summ += self.sums[i]
      i -= FenwickTree.lowbit(i)
    return summ

  @staticmethod
  def lowbit(i: int) -> int:
    return i & -i


class Solution:
  def goodTriplets(self, nums1: list[int], nums2: list[int]) -> int:
    n = len(nums1)
    numToIndex = {num: i for i, num in enumerate(nums1)}
    # Remap each number in `nums2` to the according index in `nums1` as `A`.
    # Rephrase the problem as finding the number of increasing tripets in `A`.
    A = [numToIndex[num] for num in nums2]
    # leftSmaller[i] := the number of A[j] < A[i], where 0 <= j < i
    leftSmaller = [0] * n
    # rightLarger[i] := the number of A[j] > A[i], where i < j < n
    rightLarger = [0] * n
    tree1 = FenwickTree(n)  # Calculates `leftSmaller`.
    tree2 = FenwickTree(n)  # Calculates `rightLarger`.

    for i, a in enumerate(A):
      leftSmaller[i] = tree1.get(a)
      tree1.add(a + 1, 1)

    for i, a in reversed(list(enumerate(A))):
      rightLarger[i] = tree2.get(n) - tree2.get(a)
      tree2.add(a + 1, 1)

    return sum(a * b for a, b in zip(leftSmaller, rightLarger))
