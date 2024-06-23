/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *  public:
 *   bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
 public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1])
      return 0;
    if (!sea.hasShips(topRight, bottomLeft))
      return 0;

    // sea.hashShips(topRight, bottomLeft) == true
    if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1])
      return 1;

    const int mx = (topRight[0] + bottomLeft[0]) / 2;
    const int my = (topRight[1] + bottomLeft[1]) / 2;
    int ans = 0;
    // the top-right
    ans += countShips(sea, topRight, {mx + 1, my + 1});
    // the bottom-right
    ans += countShips(sea, {topRight[0], my}, {mx + 1, bottomLeft[1]});
    // the top-left
    ans += countShips(sea, {mx, topRight[1]}, {bottomLeft[0], my + 1});
    // the bottom-left
    ans += countShips(sea, {mx, my}, bottomLeft);
    return ans;
  }
};
