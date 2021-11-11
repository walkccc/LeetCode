class Solution {
 public:
  vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    vector<pair<int, int>> events;

    for (const auto& b : buildings) {
      const int start = b[0];
      const int end = b[1];
      const int height = b[2];
      events.emplace_back(start, height);
      events.emplace_back(end, -height);
    }

    sort(begin(events), end(events));

    int prev = 0;
    int count = 0;
    int sumHeight = 0;

    for (const auto& [curr, h] : events) {
      const int height = abs(h);
      if (sumHeight > 0 && curr > prev) {
        const int avgHeight = sumHeight / count;
        if (!ans.empty() && ans.back()[1] == prev && avgHeight == ans.back()[2])
          ans.back()[1] = curr;
        else
          ans.push_back({prev, curr, avgHeight});
      }
      sumHeight += h;
      count += h > 0 ? 1 : -1;
      prev = curr;
    }

    return ans;
  }
};
