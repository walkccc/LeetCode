class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target)
      return 0;

    unordered_map<int, vector<int>> graph;  // {route: [buses]}
    unordered_set<int> usedBuses;

    for (int i = 0; i < routes.size(); ++i)
      for (const int route : routes[i])
        graph[route].push_back(i);

    int ans = 0;
    queue<int> q{{source}};

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const int route = q.front();
        q.pop();
        for (const int bus : graph[route])
          if (usedBuses.insert(bus).second)
            for (const int nextRoute : routes[bus]) {
              if (nextRoute == target)
                return ans;
              q.push(nextRoute);
            }
      }
    }

    return -1;
  }
};
