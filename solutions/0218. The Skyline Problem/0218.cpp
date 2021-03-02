class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    vector<vector<int>> events;  // {{Li, Hi} | {Ri, -Hi}}

    for (const auto& b : buildings) {
      events.push_back({b[0], b[2]});
      events.push_back({b[1], -b[2]});  // minus to indicate leaving
    }

    sort(begin(events), end(events), [](const auto& a, const auto& b) {
      // same entering, sort from higher to lower
      // same leaving, sort from lower to higher
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    for (const auto& event : events) {
      const int x = event[0];
      const int h = abs(event[1]);
      const int isEntering = event[1] > 0;
      if (isEntering) {
        if (h > maxHeight())
          ans.push_back({x, h});
        set.insert(h);
      } else {
        set.erase(set.equal_range(h).first);
        if (h > maxHeight())
          ans.push_back({x, maxHeight()});
      }
    }

    return ans;
  }

 private:
  multiset<int> set;
  int maxHeight() const {
    return set.empty() ? 0 : *rbegin(set);
  }
};
