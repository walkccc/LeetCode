class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    return accumulate(accounts.begin(), accounts.end(), 0,
                      [](int acc, const vector<int>& account) {
      return max(acc, accumulate(account.begin(), account.end(), 0));
    });
  }
};
