class Solution {
 public:
  double maxPrice(vector<vector<int>>& items, int capacity) {
    double ans = 0;

    // Sort items based on price/weight.
    ranges::sort(items, [](const vector<int>& a, const vector<int>& b) {
      return static_cast<double>(a[0]) / a[1] >
             static_cast<double>(b[0]) / b[1];
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
