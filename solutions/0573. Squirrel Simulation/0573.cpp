class Solution {
 public:
  int minDistance(int height, int width, vector<int>& tree,
                  vector<int>& squirrel, vector<vector<int>>& nuts) {
    int totDist = 0;
    int maxSave = INT_MIN;

    for (const auto& nut : nuts) {
      totDist += dist(nut, tree) * 2;
      maxSave = max(maxSave, dist(nut, tree) - dist(nut, squirrel));
    }

    return totDist - maxSave;
  }

 private:
  int dist(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }
};
