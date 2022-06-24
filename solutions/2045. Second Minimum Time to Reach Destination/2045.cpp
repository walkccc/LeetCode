class Solution {
 public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n + 1);
    queue<pair<int, int>> q{{{1, 0}}};
    // minTime[i][0] := 1st min time to reach node i
    // minTime[i][1] := 2nd min time to reach node i
    vector<vector<int>> minTime(n + 1, vector<int>(2, INT_MAX));
    minTime[1][0] = 0;

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    while (!q.empty()) {
      const auto [i, prevTime] = q.front();
      q.pop();
      // start from green
      // if numChangeSignal is odd -> now red
      // if numChangeSignal is even -> now green
      const int numChangeSignal = prevTime / change;
      const int waitTime =
          numChangeSignal & 1 ? change - (prevTime % change) : 0;
      const int newTime = prevTime + waitTime + time;
      for (const int j : graph[i])
        if (newTime < minTime[j][0]) {
          minTime[j][0] = newTime;
          q.emplace(j, newTime);
        } else if (minTime[j][0] < newTime && newTime < minTime[j][1]) {
          if (j == n)
            return newTime;
          minTime[j][1] = newTime;
          q.emplace(j, newTime);
        }
    }

    throw;
  }
};
