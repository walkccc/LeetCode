class Solution {
 public:
  int minimumLines(vector<vector<int>>& stockPrices) {
    int ans = 0;

    ranges::sort(stockPrices);

    for (int i = 2; i < stockPrices.size(); ++i) {
      const pair<int, int> a = getSlope(stockPrices[i - 2], stockPrices[i - 1]);
      const pair<int, int> b = getSlope(stockPrices[i - 1], stockPrices[i]);
      if (a != b)
        ++ans;
    }

    return ans + (stockPrices.size() > 1);
  }

 private:
  pair<int, int> getSlope(const vector<int>& p, const vector<int>& q) {
    const int dx = p[0] - q[0];
    const int dy = p[1] - q[1];
    if (dx == 0)
      return {0, p[0]};
    if (dy == 0)
      return {p[1], 0};
    const int d = __gcd(dx, dy);
    return {dx / d, dy / d};
  }
};
