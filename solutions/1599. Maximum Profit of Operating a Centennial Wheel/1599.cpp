class Solution {
 public:
  int minOperationsMaxProfit(vector<int>& customers, int boardingCost,
                             int runningCost) {
    int waiting = 0;
    int profit = 0;
    int maxProfit = 0;
    int rotate = 0;
    int maxRotate = -1;
    int i = 0;

    while (waiting > 0 || i < customers.size()) {
      if (i < customers.size())
        waiting += customers[i++];
      // Onboard new customers.
      const int newOnboard = min(waiting, 4);
      waiting -= newOnboard;
      profit += newOnboard * boardingCost - runningCost;
      ++rotate;
      if (profit > maxProfit) {
        maxProfit = profit;
        maxRotate = rotate;
      }
    }

    return maxRotate;
  }
};
