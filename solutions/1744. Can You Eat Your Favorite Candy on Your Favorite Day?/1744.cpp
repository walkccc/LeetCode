class Solution {
 public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    const int n = candiesCount.size();
    vector<bool> ans;
    vector<long> prefix{0};

    for (int i = 0; i < n; ++i)
      prefix.push_back(prefix.back() + candiesCount[i]);

    for (const vector<int>& query : queries) {
      const int type = query[0];
      const int day = query[1];
      const int cap = query[2];
      // the minimum day required to eat
      const long minDay = prefix[type] / cap;
      // the maximum day required to eat
      const long maxDay = prefix[type + 1] - 1;
      ans.push_back(minDay <= day && day <= maxDay);
    }

    return ans;
  }
};
