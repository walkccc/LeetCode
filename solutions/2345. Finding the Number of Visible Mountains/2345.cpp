class Solution {
 public:
  int visibleMountains(vector<vector<int>>& peaks) {
    int ans = 0;
    int maxRightFoot = 0;

    ranges::sort(peaks, ranges::less{}, [](const vector<int>& peak) {
      return pair<int, int>(peak[0] - peak[1], -peak[0]);
    });

    for (int i = 0; i < peaks.size(); ++i) {
      const bool overlapWithNext =
          i + 1 < peaks.size() && peaks[i] == peaks[i + 1];
      const int currRightFoot = peaks[i][0] + peaks[i][1];
      if (currRightFoot > maxRightFoot) {
        if (!overlapWithNext)
          ++ans;
        maxRightFoot = currRightFoot;
      }
    }

    return ans;
  }
};
