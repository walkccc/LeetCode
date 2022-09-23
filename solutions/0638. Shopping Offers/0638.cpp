class Solution {
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    return dfs(price, special, needs, 0);
  }

 private:
  int dfs(const vector<int>& price, const vector<vector<int>>& special,
          vector<int>& needs, int s) {
    int ans = 0;
    for (int i = 0; i < price.size(); ++i)
      ans += price[i] * needs[i];

    for (int i = s; i < special.size(); ++i)
      if (isValid(special[i], needs)) {
        // use special[i]
        for (int j = 0; j < needs.size(); ++j)
          needs[j] -= special[i][j];
        ans = min(ans, special[i].back() + dfs(price, special, needs, i));
        // backtracking - unuse special[i]
        for (int j = 0; j < needs.size(); ++j)
          needs[j] += special[i][j];
      }

    return ans;
  }

  // check if this special offer is a valid one
  bool isValid(const vector<int>& offer, const vector<int>& needs) {
    for (int i = 0; i < needs.size(); ++i)
      if (needs[i] < offer[i])
        return false;
    return true;
  }
};
