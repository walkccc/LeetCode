class Solution:
  def minOperations(self, n: int, m: int) -> int:
    isPrime = self._sieveEratosthenes(10000)
    if isPrime[n] or isPrime[m]:
      return -1
    return self._dijkstra(n, m, isPrime)

  def _dijkstra(self, src: int, dst: int, isPrime: list[bool]) -> int:
    seen = {src}
    minHeap = [(src, src)]  # (cost, num)

    while minHeap:
      cost, curr = heapq.heappop(minHeap)
      if curr == dst:
        return cost
      s = list(str(curr))
      for i, c in enumerate(s):
        if c < '9':
          s[i] = str(int(c) + 1)
          nextNum = int(''.join(s))
          if not isPrime[nextNum] and nextNum not in seen:
            heapq.heappush(minHeap, (cost + nextNum, nextNum))
            seen.add(nextNum)
          s[i] = c
        if c > '0' and not (i == 0 and c == '1'):
          s[i] = str(int(c) - 1)
          nextNum = int(''.join(s))
          if not isPrime[nextNum] and nextNum not in seen:
            heapq.heappush(minHeap, (cost + nextNum, nextNum))
            seen.add(nextNum)
          s[i] = c

    return -1

  def _sieveEratosthenes(self, n: int) -> list[bool]:
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False
    return isPrime
