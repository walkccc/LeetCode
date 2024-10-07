class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int l = ranges::max(weights);
    int r = accumulate(weights.begin(), weights.end(), 0);

    while (l < r) {
      const int m = (l + r) / 2;
      if (shipDays(weights, m) <= days)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int shipDays(const vector<int>& weights, int shipCapacity) {
    int days = 1;
    int capacity = 0;
    for (const int weight : weights)
      if (capacity + weight > shipCapacity) {
        ++days;
        capacity = weight;
      } else {
        capacity += weight;
      }
    return days;
  };
};
