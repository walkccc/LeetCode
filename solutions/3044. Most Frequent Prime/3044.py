class Solution:
  def mostFrequentPrime(self, mat: list[list[int]]) -> int:
    dirs = ((1, 0), (1, -1), (0, -1), (-1, -1),
            (-1, 0), (-1, 1), (0, 1), (1, 1))
    m = len(mat)
    n = len(mat[0])
    count = collections.Counter()

    def isPrime(num: int) -> bool:
      return not any(num % i == 0 for i in range(2, int(num**0.5 + 1)))

    for i in range(m):
      for j in range(n):
        for dx, dy in dirs:
          num = 0
          x = i
          y = j
          while 0 <= x < m and 0 <= y < n:
            num = num * 10 + mat[x][y]
            if num > 10 and isPrime(num):
              count[num] += 1
            x += dx
            y += dy

    if not count.items():
      return -1
    return max(count.items(), key=lambda x: (x[1], x[0]))[0]
