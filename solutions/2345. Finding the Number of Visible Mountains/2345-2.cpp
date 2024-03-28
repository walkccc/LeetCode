class Solution {
 public:
  int visibleMountains(vector<vector<int>>& peaks) {
    ranges::sort(peaks, [](const vector<int>& a, const vector<int>& b) {
      const int leftFootA = a[0] - a[1];
      const int leftFootB = b[0] - b[1];
      return leftFootA != leftFootB ? leftFootA < leftFootB : a[0] > b[0];
    });

    int maxRightFoot = 0;
    int result = 0;

    for (int i = 0; i < peaks.size(); ++i) {
      const bool overlapWithNext =
          i + 1 < peaks.size() && peaks[i] == peaks[i + 1];
      const int currRightFoot = peaks[i][0] + peaks[i][1];
      if (currRightFoot > maxRightFoot) {
        if (overlapWithNext == nullptr)
          ++result;
        maxRightFoot = currRightFoot;
      }
    }

    return result;
  }
};
