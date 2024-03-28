class Solution {
 public:
  long long countPaths(int n, vector<vector<int>>& edges) {
    long long ans = 0;
    const vector<bool> isPrime = sieveEratosthenes(n + 1);
    vector<vector<int>> graph(n + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 1, /*prev=*/-1, isPrime, ans);
    return ans;
  }

 private:
  pair<long, long> dfs(const vector<vector<int>>& graph, int u, int prev,
                       const vector<bool>& isPrime, long long& ans) {
    long countZeroPrimePath = !isPrime[u];
    long countOnePrimePath = isPrime[u];

    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      const auto& [countZeroPrimeChildPath, countOnePrimeChildPath] =
          dfs(graph, v, u, isPrime, ans);
      ans += countZeroPrimePath * countOnePrimeChildPath +
             countOnePrimePath * countZeroPrimeChildPath;
      if (isPrime[u]) {
        countOnePrimePath += countZeroPrimeChildPath;
      } else {
        countZeroPrimePath += countZeroPrimeChildPath;
        countOnePrimePath += countOnePrimeChildPath;
      }
    }

    return {countZeroPrimePath, countOnePrimePath};
  }

  vector<bool> sieveEratosthenes(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < n; ++i)
      if (isPrime[i])
        for (int j = i * i; j < n; j += i)
          isPrime[j] = false;
    return isPrime;
  }
};
