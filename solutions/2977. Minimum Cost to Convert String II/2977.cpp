class Solution {
 public:
  long long minimumCost(string source, string target, vector<string>& original,
                        vector<string>& changed, vector<int>& cost) {
    const unordered_set<int> subLengths = getSubLengths(original);
    const unordered_map<string, int> subToId = getSubToId(original, changed);
    const int subCount = subToId.size();
    // dist[u][v] := the minimum distance to change the substring with id u to
    // the substring with id v
    vector<vector<long>> dist(subCount, vector<long>(subCount, LONG_MAX));
    // dp[i] := the minimum cost to change the first i letters of `source` into
    // `target`, leaving the suffix untouched
    vector<long> dp(source.length() + 1, LONG_MAX);

    for (int i = 0; i < cost.size(); ++i) {
      const int u = subToId.at(original[i]);
      const int v = subToId.at(changed[i]);
      dist[u][v] = min(dist[u][v], static_cast<long>(cost[i]));
    }

    for (int k = 0; k < subCount; ++k)
      for (int i = 0; i < subCount; ++i)
        if (dist[i][k] < LONG_MAX)
          for (int j = 0; j < subCount; ++j)
            if (dist[k][j] < LONG_MAX)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    dp[0] = 0;

    for (int i = 0; i < source.length(); ++i) {
      if (dp[i] == LONG_MAX)
        continue;
      if (target[i] == source[i])
        dp[i + 1] = min(dp[i + 1], dp[i]);
      for (const int subLength : subLengths) {
        if (i + subLength > source.length())
          continue;
        const string subSource = source.substr(i, subLength);
        const string subTarget = target.substr(i, subLength);
        if (!subToId.contains(subSource) || !subToId.contains(subTarget))
          continue;
        const int u = subToId.at(subSource);
        const int v = subToId.at(subTarget);
        if (dist[u][v] < LONG_MAX)
          dp[i + subLength] = min(dp[i + subLength], dp[i] + dist[u][v]);
      }
    }

    return dp[source.length()] == LONG_MAX ? -1 : dp[source.length()];
  }

 private:
  unordered_map<string, int> getSubToId(const vector<string>& original,
                                        const vector<string>& changed) {
    unordered_map<string, int> subToId;
    for (const string& s : original)
      if (!subToId.contains(s))
        subToId[s] = subToId.size();
    for (const string& s : changed)
      if (!subToId.contains(s))
        subToId[s] = subToId.size();
    return subToId;
  }

  unordered_set<int> getSubLengths(const vector<string>& original) {
    unordered_set<int> subLengths;
    for (const string& s : original)
      subLengths.insert(s.length());
    return subLengths;
  }
};
