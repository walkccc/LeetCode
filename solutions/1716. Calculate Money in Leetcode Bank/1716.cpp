class Solution {
 public:
  int totalMoney(int n) {
    const int weeks = n / 7;
    const int firstWeek = trapezoid(1, 7);
    const int lastFullWeek = trapezoid(1 + weeks - 1, 7 + weeks - 1);
    const int remainingDays = trapezoid(1 + weeks, n % 7 + weeks);
    return (firstWeek + lastFullWeek) * weeks / 2 + remainingDays;
  }

  // Returns sum(a..b).
  int trapezoid(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
  }
};
