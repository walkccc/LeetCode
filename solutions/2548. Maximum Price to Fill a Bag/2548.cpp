class Solution {
 public:
  double maxPrice(vector<vector<int>>& items, int capacity) {
    double ans = 0;

    // Sort items based on price/weight.
    ranges::sort(items, ranges::greater{}, [](const vector<int>& item) {
      return static_cast<double>(item[0]) / item[1];
    });

    for (const vector<int>& item : items) {
      const int price = item[0];
      const int weight = item[1];
      // The bag is filled.
      if (capacity <= weight)
        return ans + price * capacity / static_cast<double>(weight);
      ans += price;
      capacity -= weight;
    }

    return -1;
  }
};
