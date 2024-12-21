class Solution {
 public:
  int brightestPosition(vector<vector<int>>& lights) {
    int ans = INT_MAX;
    int maxBrightness = -1;
    int currBrightness = 0;
    map<int, int> line;

    for (const vector<int>& light : lights) {
      const int position = light[0];
      const int range = light[1];
      ++line[position - range];
      --line[position + range + 1];
    }

    for (const auto& [pos, brightness] : line) {
      currBrightness += brightness;
      if (currBrightness > maxBrightness) {
        maxBrightness = currBrightness;
        ans = pos;
      }
    }

    return ans;
  }
};
