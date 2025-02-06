class Solution {
 public:
  int minOperations(int n, int m) {
    constexpr int kMax = 10000;
    const vector<bool> isPrime = sieveEratosthenes(kMax);
    if (isPrime[n] || isPrime[m])
      return -1;
    return dijkstra(n, m, isPrime);
  }

 private:
  int dijkstra(int src, int dst, const vector<bool>& isPrime) {
    unordered_set<int> seen{src};
    using P = tuple<int, int>;  // (cost, num)
    priority_queue<P, vector<P>, greater<>> minHeap;
    minHeap.emplace(src, src);

    while (!minHeap.empty()) {
      const auto [cost, curr] = minHeap.top();
      minHeap.pop();
      if (curr == dst)
        return cost;
      string s = to_string(curr);
      for (int i = 0; i < s.length(); ++i) {
        if (s[i] < '9') {
          ++s[i];
          const int next = stoi(s);
          if (!isPrime[next] && !seen.contains(next)) {
            minHeap.emplace(cost + next, next);
            seen.insert(next);
          }
          --s[i];
        }
        if (s[i] > '0' && !(i == 0 && s[i] == '1')) {
          --s[i];
          const int next = stoi(s);
          if (!isPrime[next] && !seen.contains(next)) {
            minHeap.emplace(cost + next, next);
            seen.insert(next);
          }
          ++s[i];
        }
      }
    }

    return -1;
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
