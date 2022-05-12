struct T {
  int node;
  int cost;
  int time;
  T(int node, int cost, int time) : node(node), cost(cost), time(time) {}
};

class Solution {
 public:
  int minCost(int maxTime, vector<vector<int>>& edges,
              vector<int>& passingFees) {
    const int n = passingFees.size();
    vector<vector<pair<int, int>>> graph(n);
    auto compare = [](const T& a, const T& b) {
      return a.cost == b.cost ? a.time > b.time : a.cost > b.cost;
    };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    vector<int> cost(n, INT_MAX);  // cost[i] := min cost to reach cities[i]
    vector<int> time(n, INT_MAX);  // time[i] := min time to reach cities[i]

    for (const auto& e : edges) {
      const int x = e[0];
      const int y = e[1];
      const int t = e[2];
      graph[x].emplace_back(y, t);
      graph[y].emplace_back(x, t);
    }

    // start with node 0 with cost = time = 0
    minHeap.emplace(0, passingFees[0], 0);
    cost[0] = passingFees[0];
    time[0] = 0;

    while (!minHeap.empty()) {
      const auto [x, currCost, currTime] = minHeap.top();
      minHeap.pop();
      for (const auto& [y, pathTime] : graph[x]) {
        if (currTime + pathTime <= maxTime) {
          // go from x -> y
          const int newCost = currCost + passingFees[y];
          const int newTime = currTime + pathTime;
          if (cost[y] > newCost) {
            cost[y] = newCost;
            time[y] = newTime;
            minHeap.emplace(y, newCost, newTime);
          } else if (time[y] > newTime) {
            time[y] = newTime;
            minHeap.emplace(y, newCost, newTime);
          }
        }
      }
    }

    return cost.back() == INT_MAX ? -1 : cost.back();
  }
};
