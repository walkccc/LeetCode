class Solution {
 public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> xs;
    vector<pair<int, int>> ys;

    for (const vector<int> rectangles : rectangles) {
      const int startX = rectangles[0];
      const int startY = rectangles[1];
      const int endX = rectangles[2];
      const int endY = rectangles[3];
      xs.emplace_back(startX, endX);
      ys.emplace_back(startY, endY);
    }

    return max(countMerged(xs), countMerged(ys)) >= 3;
  }

 private:
  int countMerged(vector<pair<int, int>>& intervals) {
    int count = 0;
    int prevEnd = 0;

    ranges::sort(intervals);

    for (const auto& [start, eend] : intervals)
      if (start < prevEnd) {
        prevEnd = max(prevEnd, eend);
      } else {
        prevEnd = eend;
        ++count;
      }

    return count;
  }
};
