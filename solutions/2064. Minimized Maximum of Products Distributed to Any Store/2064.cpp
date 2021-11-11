class Solution {
 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1;
    int r = *max_element(begin(quantities), end(quantities));

    auto numOfStores = [&](int x) {
      int nStores = 0;
      for (const int q : quantities)
        nStores += (q - 1) / x + 1;  // ceil(q / k)
      return nStores;
    };

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (numOfStores(m) <= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
