class Solution:
  def countPaths(self, n: int, edges: List[List[int]]) -> int:
    ans = 0
    isPrime = self._sieveEratosthenes(n + 1)
    graph = [[] for _ in range(n + 1)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    def dfs(u: int, prev: int) -> Tuple[int, int]:
      nonlocal ans
      countZeroPrimePath = int(not isPrime[u])
      countOnePrimePath = int(isPrime[u])

      for v in graph[u]:
        if v == prev:
          continue
        countZeroPrimeChildPath, countOnePrimeChildPath = dfs(v, u)
        ans += countZeroPrimePath * countOnePrimeChildPath + \
            countOnePrimePath * countZeroPrimeChildPath
        if isPrime[u]:
          countOnePrimePath += countZeroPrimeChildPath
        else:
          countZeroPrimePath += countZeroPrimeChildPath
          countOnePrimePath += countOnePrimeChildPath

      return countZeroPrimePath, countOnePrimePath

    dfs(1, -1)
    return ans

  def _sieveEratosthenes(self, n: int) -> List[bool]:
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False
    return isPrime
