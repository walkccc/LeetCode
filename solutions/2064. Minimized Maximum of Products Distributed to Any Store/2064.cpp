class Solution {
 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1;
    int r = *max_element(begin(quantities), end(quantities));

    while (l < r) {
      const int m = (l + r) / 2;
      if (numOfStores(quantities, m) <= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numOfStores(const vector<int>& quantities, int m) {
    // ceil(q / k)
    return accumulate(
        begin(quantities), end(quantities), 0,
        [&](int subtotal, int q) { return subtotal + (q - 1) / m + 1; });
  }
};
