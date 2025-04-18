class Solution {
 public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    double ans = 0;
    int prev = 0;

    for (const vector<int>& b : brackets) {
      const int upper = b[0];
      const int percent = b[1];
      if (income < upper)
        return ans + (income - prev) * percent / 100.0;
      ans += (upper - prev) * percent / 100.0;
      prev = upper;
    }

    return ans;
  }
};
