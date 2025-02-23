class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    int numLines = 1;
    int runningWidth = 0;

    for (const char c : s) {
      const int width = widths[c - 'a'];
      if (runningWidth + width <= 100) {
        runningWidth += width;
      } else {
        ++numLines;
        runningWidth = width;
      }
    }

    return {numLines, runningWidth};
  }
};
