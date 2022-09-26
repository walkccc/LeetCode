class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();
    // cost[i][j] := cost to append A[j] after A[i]
    vector<vector<int>> cost(n, vector<int>(n));

    // getCost(a, b) := cost to append b after a
    auto getCost = [](const string& a, const string& b) {
      int cost = b.length();
      const int minLength = min(a.length(), b.length());
      for (int k = 1; k <= minLength; ++k)
        if (a.substr(a.length() - k) == b.substr(0, k))
          cost = b.length() - k;
      return cost;
    };

    // pre-calculate cost array to save time
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cost[i][j] = getCost(A[i], A[j]);
        cost[j][i] = getCost(A[j], A[i]);
      }

    vector<int> bestPath;
    int minLength = n * 20;  // given by problem

    dfs(A, cost, {}, bestPath, 0, 0, 0, minLength);

    string ans = A[bestPath[0]];

    for (int k = 1; k < n; ++k) {
      const int i = bestPath[k - 1];
      const int j = bestPath[k];
      ans += A[j].substr(A[j].length() - cost[i][j]);
    }

    return ans;
  }

 private:
  // used: i-th bit means A[i] is used or not
  void dfs(const vector<string>& A, const vector<vector<int>>& cost,
           vector<int>&& path, vector<int>& bestPath, int used, int depth,
           int currLength, int& minLength) {
    if (currLength >= minLength)
      return;
    if (depth == A.size()) {
      minLength = currLength;
      bestPath = path;
      return;
    }

    for (int i = 0; i < A.size(); ++i) {
      if (1 << i & used)
        continue;
      path.push_back(i);
      const int newLength =
          depth == 0 ? A[i].length() : currLength + cost[path[depth - 1]][i];
      dfs(A, cost, move(path), bestPath, used | 1 << i, depth + 1, newLength,
          minLength);
      path.pop_back();
    }
  }
};
