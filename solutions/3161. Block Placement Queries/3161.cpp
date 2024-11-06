class FenwickTree {
 public:
  FenwickTree(int n) : vals(n + 1) {}

  void maximize(int i, int val) {
    while (i < vals.size()) {
      vals[i] = max(vals[i], val);
      i += lowbit(i);
    }
  }

  int get(int i) const {
    int res = 0;
    while (i > 0) {
      res = max(res, vals[i]);
      i -= lowbit(i);
    }
    return res;
  }

 private:
  vector<int> vals;

  static int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  vector<bool> getResults(vector<vector<int>>& queries) {
    const int n = min(50000, static_cast<int>(queries.size()) * 3);
    vector<bool> ans;
    FenwickTree tree(n + 1);
    set<int> obstacles{0, n};  // sentinel values

    for (const vector<int>& query : queries) {
      const int type = query[0];
      if (type == 1) {
        const int x = query[1];
        obstacles.insert(x);
      }
    }

    for (auto it = obstacles.begin(); std::next(it) != obstacles.end(); ++it) {
      const int x1 = *it;
      const int x2 = *std::next(it);
      tree.maximize(x2, x2 - x1);
    }

    for (int i = queries.size() - 1; i >= 0; --i) {
      const int type = queries[i][0];
      const int x = queries[i][1];
      if (type == 1) {
        const auto it = obstacles.find(x);
        if (next(it) != obstacles.end())  // x is not the last element.
          tree.maximize(*next(it), *next(it) - *prev(it));
        obstacles.erase(it);
      } else {
        const int sz = queries[i][2];
        const auto it = obstacles.upper_bound(x);
        const int prev = *std::prev(it);
        ans.push_back(tree.get(prev) >= sz || x - prev >= sz);
      }
    }

    ranges::reverse(ans);
    return ans;
  }
};
