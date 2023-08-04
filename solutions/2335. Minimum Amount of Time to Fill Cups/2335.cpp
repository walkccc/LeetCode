class Solution {
 public:
  int fillCups(vector<int>& amount) {
    const int max = *max_element(amount.begin(), amount.end());
    const int sum = accumulate(amount.begin(), amount.end(), 0);
    return std::max(max, (sum + 1) / 2);
  }
};
