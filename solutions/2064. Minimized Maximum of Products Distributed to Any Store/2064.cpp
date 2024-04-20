class Solution {
 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1;
    int r = ranges::max(quantities);

    while (l < r) {
      const int m = (l + r) / 2;
      if (numStores(quantities, m) <= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numStores(const vector<int>& quantities, int m) {
    // ceil(q / m)
    return accumulate(
        quantities.begin(), quantities.end(), 0,
        [&](int subtotal, int q) { return subtotal + (q - 1) / m + 1; });
  }
};
