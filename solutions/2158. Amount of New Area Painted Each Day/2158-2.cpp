class Solution {
 public:
  vector<int> amountPainted(vector<vector<int>>& paint) {
    map<int, int> intervals;
    vector<int> result;

    for (const vector<int>& p : paint) {
      int eraseLen = 0;
      auto it = intervals.lower_bound(p[0]);
      if (it != intervals.begin() && prev(it)->second >= p[0])
        --it;
      while (it != intervals.end() && p[1] >= it->first) {
        eraseLen += it->second - it->first;
        p[0] = min(p[0], it->first);
        p[1] = max(p[1], it->second);
        it = intervals.erase(it);
      }
      intervals.insert({p[0], p[1]});
      result.push_back(p[1] - p[0] - eraseLen);
    }

    return result;
  }
};
