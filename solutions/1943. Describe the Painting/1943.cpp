class Solution {
 public:
  vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    vector<vector<long long>> ans;
    int prevIndex = 0;
    long runningMix = 0;
    map<int, long> line;

    for (const vector<int>& segment : segments) {
      const int start = segment[0];
      const int end = segment[1];
      const int color = segment[2];
      line[start] += color;
      line[end] -= color;
    }

    for (const auto& [i, mix] : line) {
      if (runningMix > 0)
        ans.push_back({prevIndex, i, runningMix});
      runningMix += mix;
      prevIndex = i;
    }

    return ans;
  }
};
