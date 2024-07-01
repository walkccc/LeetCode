class Solution:
  def isAdditiveNumber(self, num: str) -> bool:
    n = len(num)

    def dfs(firstNum: int, secondNum: int, s: int) -> bool:
      if s == len(num):
        return True

      thirdNum = firstNum + secondNum
      thirdNumStr = str(thirdNum)

      return num.find(thirdNumStr, s) == s and dfs(secondNum, thirdNum, s + len(thirdNumStr))

    # num[0..i] = firstNum
    for i in range(n // 2):
      if i > 0 and num[0] == '0':
        return False
      firstNum = int(num[:i + 1])
      # num[i + 1..j] = secondNum
      # |thirdNum| >= max(|firstNum|, |secondNum|)
      j = i + 1
      while max(i, j - i) < n - j:
        if j > i + 1 and num[i + 1] == '0':
          break
        secondNum = int(num[i + 1:j + 1])
        if dfs(firstNum, secondNum, j + 1):
          return True
        j += 1

    return False
