class Solution {
 public:
  int fillCups(vector<int>& amount) {
    const int max = ranges::max(amount);
    const int sum = accumulate(amount.begin(), amount.end(), 0);
    return std::max(max, (sum + 1) / 2);
  }
};
