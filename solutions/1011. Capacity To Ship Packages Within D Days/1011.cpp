class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int l = *max_element(begin(weights), end(weights));
    int r = accumulate(begin(weights), end(weights), 0);

    auto shipDays = [&](int shipCapacity) {
      int days = 1;
      int capacity = 0;
      for (const int weight : weights) {
        if (capacity + weight > shipCapacity) {
          ++days;
          capacity = weight;
        } else {
          capacity += weight;
        }
      }
      return days;
    };

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (shipDays(m) <= days)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
