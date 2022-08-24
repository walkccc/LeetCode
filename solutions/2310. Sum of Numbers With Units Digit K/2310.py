class Solution:
  def minimumNumbers(self, num: int, k: int) -> int:
    if num == 0:
      return 0

    # Assume the size of the set is n, and the numbers in the set are X1, X2,
    # ..., Xn. Since the units digit of each number is k, X1 + X2 + ... + Xn =
    # n * k + 10 * (x1 + x2 + ... + xn) = num. Therefore, the goal is to find
    # the n s.t. n * k % 10 = num % 10
    for i in range(1, 11):
      if i * k > num + 1:
        break
      if i * k % 10 == num % 10:
        return i

    return -1
