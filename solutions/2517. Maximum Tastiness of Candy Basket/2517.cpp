class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    int l = 0;
    int r = *max_element(begin(price), end(price)) -
            *min_element(begin(price), end(price)) + 1;

    sort(begin(price), end(price));

    while (l < r) {
      const int m = (l + r) / 2;
      if (maxSize(price, m) >= k)
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

 private:
  // Returns the max size basket of m tastiness.
  int maxSize(const vector<int>& price, int m) {
    int size = 0;
    int prevPrice = -m;
    for (const int p : price)
      if (p >= prevPrice + m) {
        prevPrice = p;
        ++size;
      }
    return size;
  }
};
