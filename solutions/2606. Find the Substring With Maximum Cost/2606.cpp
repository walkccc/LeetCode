class Solution {
 public:
  int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int ans = 0;
    int cost = 0;
    vector<int> costs(26);  // costs[i] := the cost of 'a' + i

    iota(costs.begin(), costs.end(), 1);

    for (int i = 0; i < chars.size(); ++i)
      costs[chars[i] - 'a'] = vals[i];

    for (const char c : s) {
      cost = max(0, cost + costs[c - 'a']);
      ans = max(ans, cost);
    }

    return ans;
  }
};
