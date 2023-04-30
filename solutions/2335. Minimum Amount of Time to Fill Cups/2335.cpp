class Solution {
 public:
  int fillCups(vector<int>& amount) {
    const int max = *max_element(begin(amount), end(amount));
    const int sum = accumulate(begin(amount), end(amount), 0);
    return std::max(max, (sum + 1) / 2);
  }
};
