struct T {
  int u;
  int d;
  int leftDiscounts;
};

class Solution {
 public:
  int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
    vector<vector<pair<int, int>>> graph(n);
    auto compare = [](const T& a, const T& b) { return a.d > b.d; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    unordered_map<int, int> minDiscounts;

    for (const vector<int>& h : highways) {
      const int city1 = h[0];
      const int city2 = h[1];
      const int toll = h[2];
      graph[city1].emplace_back(city2, toll);
      graph[city2].emplace_back(city1, toll);
    }

    minHeap.emplace(0, 0, discounts);

    while (!minHeap.empty()) {
      const auto [u, d, leftDiscounts] = minHeap.top();
      minHeap.pop();
      if (u == n - 1)
        return d;
      if (const auto it = minDiscounts.find(u);
          it != minDiscounts.cend() && it->second >= leftDiscounts)
        continue;
      minDiscounts[u] = leftDiscounts;
      for (const auto& [v, w] : graph[u]) {
        minHeap.emplace(v, d + w, leftDiscounts);
        if (leftDiscounts > 0)
          minHeap.emplace(v, d + w / 2, leftDiscounts - 1);
      }
    }

    return -1;
  }
};
