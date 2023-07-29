class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());

    int l = 0;
    int r = *max_element(price.begin(), price.end()) -
            *min_element(price.begin(), price.end()) + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (numBaskets(price, m) >= k)
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

 private:
  // Returns the # of baskets we can pick for m tastiness.
  int numBaskets(const vector<int>& price, int m) {
    int baskets = 0;
    int prevPrice = -m;
    for (const int p : price)
      if (p >= prevPrice + m) {
        prevPrice = p;
        ++baskets;
      }
    return baskets;
  }
};
