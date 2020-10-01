class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    unordered_map<string, int> memo;

    function<int(const string&, int)> dfs = [&](const string& ring, int s) {
      if (s == key.length()) return 0;
      // add the index to prevent duplicate
      const string hashKey = ring + to_string(s);
      if (memo.count(hashKey)) return memo[hashKey];

      int ans = INT_MAX;

      for (size_t i = 0; i < ring.length(); ++i)
        if (ring[i] == key[s]) {
          // #rotates of the ring to match key[s]
          const int diff = min(i, ring.length() - i);
          // match next index
          const int step = dfs(ring.substr(i) + ring.substr(0, i), s + 1);
          ans = min(ans, diff + step);
        }

      return memo[hashKey] = ans;
    };

    return dfs(ring, 0) + key.length();
  }
};