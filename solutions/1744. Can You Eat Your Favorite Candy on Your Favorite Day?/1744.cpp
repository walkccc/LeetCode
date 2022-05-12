class Solution {
 public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    const int n = candiesCount.size();
    vector<bool> ans;
    vector<long> prefix(n + 1);

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + candiesCount[i];

    for (const auto& q : queries) {
      const int type = q[0];
      const int day = q[1];
      const int cap = q[2];
      // min/max day required to eat
      const long minDay = prefix[type] / cap;
      const long maxDay = prefix[type + 1] - 1;
      ans.push_back(minDay <= day && day <= maxDay);
    }

    return ans;
  }
};
