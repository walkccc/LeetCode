class Solution {
 public:
  int fillCups(vector<int>& amount) {
    const int mx = ranges::max(amount);
    const int sum = accumulate(amount.begin(), amount.end(), 0);
    return max(mx, (sum + 1) / 2);
  }
};
