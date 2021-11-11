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

    for (const auto& edge : edges) {
      const int x = edge[0];
      const int y = edge[1];
      const int time = edge[2];
      graph[x].emplace_back(y, time);
      graph[y].emplace_back(x, time);
    }

    vector<int> cost(n, INT_MAX);  // cost[i] := min cost to reach cities[i]
    vector<int> time(n, INT_MAX);  // time[i] := min time to reach cities[i]

    cost[0] = passingFees[0];
    time[0] = 0;

    auto compare = [](const T& a, const T& b) {
      return a.cost == b.cost ? a.time > b.time : a.cost > b.cost;
    };
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);
    pq.emplace(0, cost[0], time[0]);  // start with node 0 with cost = time = 0

    while (!pq.empty()) {
      const auto [x, currCost, currTime] = pq.top();
      pq.pop();
      for (const auto& [y, pathTime] : graph[x]) {
        if (currTime + pathTime <= maxTime) {
          // go from x -> y
          const int newCost = currCost + passingFees[y];
          const int newTime = currTime + pathTime;
          if (cost[y] > newCost) {
            cost[y] = newCost;
            time[y] = newTime;
            pq.emplace(y, newCost, newTime);
          } else if (time[y] > newTime) {
            time[y] = newTime;
            pq.emplace(y, newCost, newTime);
          }
        }
      }
    }

    return cost.back() == INT_MAX ? -1 : cost.back();
  }
};
