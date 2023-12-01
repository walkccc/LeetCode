class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    long largestCount = 1;

    ranges::sort(inventory, greater<>());

    for (int i = 0; i < inventory.size(); ++i, ++largestCount)
      if (i == inventory.size() - 1 || inventory[i] > inventory[i + 1]) {
        // If we are at the last inventory, or inventory[i] > inventory[i + 1].
        // In either case, we will pick inventory[i - largestCount + 1..i].
        const int pick = (i == inventory.size() - 1)
                             ? inventory[i]
                             : inventory[i] - inventory[i + 1];
        if (largestCount * pick >= orders) {
          // We have run out of orders, so we need to recalculate the number of
          // balls that we actually pick for inventory[i - largestCount + 1..i].
          const int actualPick = orders / largestCount;
          const int remaining = orders % largestCount;
          return (ans +
                  largestCount *
                      trapezoid(inventory[i], inventory[i] - actualPick + 1) +
                  remaining * static_cast<long>(inventory[i] - actualPick)) %
                 kMod;
        }
        ans += largestCount * trapezoid(inventory[i], inventory[i] - pick + 1);
        ans %= kMod;
        orders -= largestCount * pick;
      }

    throw;
  }

 private:
  long trapezoid(long a, long b) {
    return (a + b) * (a - b + 1) / 2;
  }
};
