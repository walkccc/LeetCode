class Solution {
  public long countPaths(int n, int[][] edges) {
    final boolean[] isPrime = sieveEratosthenes(n + 1);
    List<Integer>[] graph = new List[n + 1];

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(graph, 1, /*prev=*/-1, isPrime);
    return ans;
  }

  private long ans = 0;

  private Pair<Long, Long> dfs(List<Integer>[] graph, int u, int prev, boolean[] isPrime) {
    long countZeroPrimePath = isPrime[u] ? 0 : 1;
    long countOnePrimePath = isPrime[u] ? 1 : 0;

    for (final int v : graph[u]) {
      if (v == prev)
        continue;
      Pair<Long, Long> pair = dfs(graph, v, u, isPrime);
      final long countZeroPrimeChildPath = pair.getKey();
      final long countOnePrimeChildPath = pair.getValue();
      ans +=
          countZeroPrimePath * countOnePrimeChildPath + countOnePrimePath * countZeroPrimeChildPath;
      if (isPrime[u]) {
        countOnePrimePath += countZeroPrimeChildPath;
      } else {
        countZeroPrimePath += countZeroPrimeChildPath;
        countOnePrimePath += countOnePrimeChildPath;
      }
    }

    return new Pair<>(countZeroPrimePath, countOnePrimePath);
  }

  private boolean[] sieveEratosthenes(int n) {
    boolean[] isPrime = new boolean[n];
    Arrays.fill(isPrime, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < n; ++i)
      if (isPrime[i])
        for (int j = i * i; j < n; j += i)
          isPrime[j] = false;
    return isPrime;
  }
}
