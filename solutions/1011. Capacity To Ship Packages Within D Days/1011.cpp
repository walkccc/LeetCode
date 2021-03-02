class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int D) {
    int l = *max_element(begin(weights), end(weights));
    int r = accumulate(begin(weights), end(weights), 0);

    while (l < r) {
      int m = l + (r - l) / 2;
      int day = 1;
      int capacity = 0;
      for (int weight : weights) {
        if (capacity + weight > m) {
          ++day;
          capacity = weight;
        } else
          capacity += weight;
      }
      if (day <= D)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
