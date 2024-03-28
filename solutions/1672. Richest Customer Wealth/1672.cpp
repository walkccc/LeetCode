class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    return accumulate(accounts.begin(), accounts.end(), 0,
                      [](int maxAccountSum, const vector<int>& account) {
      return max(maxAccountSum, accumulate(account.begin(), account.end(), 0));
    });
  }
};
