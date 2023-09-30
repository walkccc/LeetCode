class Solution:
  def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
    n = len(receiver)
    m = int(math.log2(k)) + 1
    ans = 0
    # jump[i][j] := node you reach after jumping 2^j steps from i
    jump = [[0] * m for _ in range(n)]
    # summ[i][j] := sum of first 2^j nodes you reach when jumping from i
    summ = [[0] * m for _ in range(n)]

    for i in range(n):
      jump[i][0] = receiver[i]
      summ[i][0] = receiver[i]

    # Binary lifting.
    for j in range(1, m):
      for i in range(n):
        midNode = jump[i][j - 1]
        #   node you reach after jumping 2^j steps from i
        # = node you reach after jumping 2^(j - 1) steps from i
        # + node you reach after jumping another 2^(j - 1) steps
        jump[i][j] = jump[midNode][j - 1]
        #   sum of first 2^j nodes you reach when jumping from i
        # = sum of first 2^(j - 1) nodes you reach when jumping from i
        # + sum of another 2^(j - 1) nodes you reach
        summ[i][j] = summ[i][j - 1] + summ[midNode][j - 1]

    for i in range(n):
      currSum = i
      currPos = i
      for j in range(m):
        if (k >> j) & 1 == 1:
          currSum += summ[currPos][j]
          currPos = jump[currPos][j]
      ans = max(ans, currSum)

    return ans
