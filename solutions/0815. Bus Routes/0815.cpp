class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T)
      return 0;

    unordered_set<int> usedBuses;
    unordered_map<int, vector<int>> graph;  // {route: [buses]}

    for (int i = 0; i < routes.size(); ++i)
      for (const int route : routes[i])
        graph[route].push_back(i);

    int ans = 0;
    queue<int> q{{S}};

    while (!q.empty()) {
      ++ans;
      for (int size = q.size(); size > 0; --size) {
        const int route = q.front();
        q.pop();
        for (const int bus : graph[route])
          if (usedBuses.insert(bus).second)
            for (const int nextRoute : routes[bus])
              if (nextRoute == T)
                return ans;
              else
                q.push(nextRoute);
      }
    }

    return -1;
  }
};
