class Solution:
  def maxSizedArray(self, s: int) -> int:
    def getNumbersWithBitSet(n: int, i: int) -> int:
      """
      Returns the number of integers in [0, n - 1] with the i-th bit set.

      For the i-th bit, numbers in the range [0, n - 1] can be divided into
      groups of 2^(i + 1) numbers. In each group, exactly half of the numbers
      have the i-th bit set.
      """
      groupSize = 1 << (i + 1)
      halfGroupSize = 1 << i
      fullGroups = n // groupSize
      remaining = max(0, (n % groupSize) - halfGroupSize)
      return fullGroups * halfGroupSize + remaining

    def getArraySum(n: int) -> int:
      """
      Returns the sum of all i * (j OR k) values in 3D arrays of size n^3.

        sum(i * (j OR k)), where 0 <= i, j, k < n
      = 0 * (j OR k) + 1 * (j OR k) + ... + (n - 1) * (j OR k)
      = (0 + 1 + ... + n - 1) * sum(j OR k)
      = (n * (n - 1) / 2) * sum(j OR k)
      """
      arithmeticSum = n * (n - 1) // 2  # 0 + 1 + ... + n - 1
      orSum = 0  # the sum of (j OR k) values in 2D arrays of size n^2
      for i in range(n.bit_length()):
        numbersWithoutBit = n - getNumbersWithBitSet(n, i)
        pairsWithBit = n**2 - numbersWithoutBit**2
        orSum += pairsWithBit * (1 << i)  # Add contribution of this bit.
      return arithmeticSum * orSum

    if s == 0:
      return 1
    l = 0
    r = 1196  # when s = 10^15, n = 1196
    return bisect.bisect_right(range(l, r + 1), s, key=getArraySum) - 1 + l
