class Solution {
 public:
  vector<int> fallingSquares(vector<vector<int>>& positions) {
    vector<int> ans;
    map<pair<int, int>, int> xsToHeight;  // {{xStart, xEnd}, height}
    int maxHeight = INT_MIN;

    for (const auto& p : positions) {
      const int left = p[0];
      const int sideLength = p[1];
      const int right = left + sideLength;
      // first range intersect with [left, right)
      auto it = xsToHeight.upper_bound({left, right});
      if (it != begin(xsToHeight) && (--it)->first.second <= left)
        ++it;
      int maxHeightInRange = 0;
      vector<tuple<int, int, int>> ranges;
      while (it != end(xsToHeight) && it->first.first < right) {
        const int l = it->first.first;
        const int r = it->first.second;
        const int h = it->second;
        if (l < left)
          ranges.emplace_back(l, left, h);
        if (right < r)
          ranges.emplace_back(right, r, h);
        maxHeightInRange = max(maxHeightInRange, h);
        it = xsToHeight.erase(it);
      }
      const int newHeight = maxHeightInRange + sideLength;
      xsToHeight[{left, right}] = newHeight;
      for (const auto& [l, r, h] : ranges)
        xsToHeight[{l, r}] = h;
      maxHeight = max(maxHeight, newHeight);
      ans.push_back(maxHeight);
    }

    return ans;
  }
};
