class Solution {
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    const int n = needs.size();

    function<int(int)> dfs = [&](int s) {
      int ans = 0;
      for (int i = 0; i < n; ++i)
        ans += price[i] * needs[i];

      for (int i = s; i < special.size(); ++i)
        if (isValid(special[i], needs)) {
          // use special[i]
          for (int j = 0; j < n; ++j)
            needs[j] -= special[i][j];
          ans = min(ans, special[i].back() + dfs(i));
          // backtracking - unuse special[i]
          for (int j = 0; j < n; ++j)
            needs[j] += special[i][j];
        }

      return ans;
    };

    return dfs(0);
  }

 private:
  // check if this special offer is a valid one
  bool isValid(const vector<int>& offer, const vector<int>& needs) {
    for (int i = 0; i < needs.size(); ++i)
      if (needs[i] < offer[i])
        return false;
    return true;
  }
};