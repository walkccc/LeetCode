class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    // the maximum <= the minimum + the middle
    const int x = (a + b + c) / 2;
    // the maximum > the minimum + the middle
    const int y = a + b + c - max({a, b, c});
    return min(x, y);
  }
};
