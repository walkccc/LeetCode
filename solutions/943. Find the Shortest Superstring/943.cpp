class Solution {
 public:
  string shortestSuperstring(vector<string>& words) {
    const int n = words.size();
    // cost[i][j] := the cost to append words[j] after words[i]
    vector<vector<int>> cost(n, vector<int>(n));

    // Returns the cost to append b after a.
    auto getCost = [](const string& a, const string& b) {
      int cost = b.length();
      const int minLength = min(a.length(), b.length());
      for (int k = 1; k <= minLength; ++k)
        if (a.substr(a.length() - k) == b.substr(0, k))
          cost = b.length() - k;
      return cost;
    };

    // Pre-calculate cost array to save time.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cost[i][j] = getCost(words[i], words[j]);
        cost[j][i] = getCost(words[j], words[i]);
      }

    vector<int> bestPath;
    int minLength = n * 20;  // given by problem

    dfs(words, cost, {}, bestPath, 0, 0, 0, minLength);

    string ans = words[bestPath[0]];

    for (int k = 1; k < n; ++k) {
      const int i = bestPath[k - 1];
      const int j = bestPath[k];
      ans += words[j].substr(words[j].length() - cost[i][j]);
    }

    return ans;
  }

 private:
  // used: i-th bit means words[i] is used or not
  void dfs(const vector<string>& words, const vector<vector<int>>& cost,
           vector<int>&& path, vector<int>& bestPath, int used, int depth,
           int currLength, int& minLength) {
    if (currLength >= minLength)
      return;
    if (depth == words.size()) {
      minLength = currLength;
      bestPath = path;
      return;
    }

    for (int i = 0; i < words.size(); ++i) {
      if (used >> i & 1)
        continue;
      path.push_back(i);
      const int newLength = depth == 0 ? words[i].length()
                                       : currLength + cost[path[depth - 1]][i];
      dfs(words, cost, std::move(path), bestPath, used | 1 << i, depth + 1,
          newLength, minLength);
      path.pop_back();
    }
  }
};
