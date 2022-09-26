class Solution {
 public:
  int maximumCandies(vector<int>& candies, long long k) {
    int l = 1;
    int r = accumulate(begin(candies), end(candies), 0L) / k;

    while (l < r) {
      const int m = (l + r) / 2;
      if (numChildren(candies, m) < k)
        r = m;
      else
        l = m + 1;
    }

    return numChildren(candies, l) >= k ? l : l - 1;
  }

 private:
  long numChildren(const vector<int>& candies, int m) {
    return accumulate(begin(candies), end(candies), 0L,
                      [&](long subtotal, int c) { return subtotal + c / m; });
  };
};
