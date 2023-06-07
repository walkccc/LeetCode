class Solution:
  def kMirror(self, k: int, n: int) -> int:
    ans = 0
    A = ['0']

    def nextKMirror(A: List[chr]) -> List[chr]:
      for i in range(len(A) // 2, len(A)):
        nextNum = int(A[i]) + 1
        if nextNum < k:
          A[i] = str(nextNum)
          A[~i] = str(nextNum)
          for j in range(len(A) // 2, i):
            A[j] = '0'
            A[~j] = '0'
          return A
      return ['1'] + ['0'] * (len(A) - 1) + ['1']

    for _ in range(n):
      while True:
        A = nextKMirror(A)
        num = int(''.join(A), k)
        if str(num)[::-1] == str(num):
          break
      ans += num

    return ans
