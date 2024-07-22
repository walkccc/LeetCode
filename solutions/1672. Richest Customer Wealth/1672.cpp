class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    return accumulate(accounts.begin(), accounts.end(), 0,
                      [](int subtotal, const vector<int>& account) {
      return max(subtotal, accumulate(account.begin(), account.end(), 0));
    });
  }
};
