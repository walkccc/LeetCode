class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    vector<int> minSides;

    for (const vector<int>& rectangle : rectangles) {
      const int x = rectangle[0];
      const int y = rectangle[1];
      minSides.push_back(min(x, y));
    }

    const int maxLen = ranges::max(minSides);
    return ranges::count(minSides, maxLen);
  }
};
