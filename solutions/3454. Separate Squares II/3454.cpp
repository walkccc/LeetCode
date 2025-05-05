class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& xs)
      : xs(xs), n(xs.size() - 1), coveredCount(4 * n), coveredWidth(4 * n) {}

  // Adds val to the range [i, j].
  void add(int i, int j, int val) {
    add(0, 0, n - 1, i, j, val);
  }

  // Returns the covered width of xs[0..n - 1].
  int getCoveredWidth() const {
    return coveredWidth[0];
  }

 private:
  const int n;  // the number of segments (|xs| - 1)
  vector<int> xs;
  vector<int> coveredCount;
  vector<int> coveredWidth;

  void add(int treeIndex, int lo, int hi, int i, int j, int val) {
    if (j <= xs[lo] || xs[hi + 1] <= i)
      return;
    if (i <= xs[lo] && xs[hi + 1] <= j) {
      coveredCount[treeIndex] += val;
    } else {
      const int mid = (lo + hi) / 2;
      add(2 * treeIndex + 1, lo, mid, i, j, val);
      add(2 * treeIndex + 2, mid + 1, hi, i, j, val);
    }
    if (coveredCount[treeIndex] > 0) {
      coveredWidth[treeIndex] = xs[hi + 1] - xs[lo];
    } else if (lo == hi) {
      coveredWidth[treeIndex] = 0;
    } else {
      coveredWidth[treeIndex] =
          coveredWidth[2 * treeIndex + 1] + coveredWidth[2 * treeIndex + 2];
    }
  }
};

class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    vector<tuple<int, int, int, int>> events;  // (y, delta, xl, xr)
    set<int> xs;

    for (const vector<int>& square : squares) {
      const int x = square[0];
      const int y = square[1];
      const int l = square[2];
      events.emplace_back(y, 1, x, x + l);
      events.emplace_back(y + l, -1, x, x + l);
      xs.insert(x);
      xs.insert(x + l);
    }

    ranges::sort(events);

    const double halfArea = getArea(events, xs) / 2.0;
    long area = 0;
    int prevY = 0;
    SegmentTree tree({xs.begin(), xs.end()});

    for (const auto& [y, delta, xl, xr] : events) {
      const int coveredWidth = tree.getCoveredWidth();
      const long areaGain = coveredWidth * static_cast<long>(y - prevY);
      if (area + areaGain >= halfArea)
        return prevY + (halfArea - area) / coveredWidth;
      area += areaGain;
      tree.add(xl, xr, delta);
      prevY = y;
    }

    throw;
  }

 private:
  // Returns the total area of the rectangles.
  long getArea(const vector<tuple<int, int, int, int>>& events,
               const set<int>& xs) {
    long totalArea = 0;
    int prevY = 0;
    SegmentTree tree({xs.begin(), xs.end()});
    for (const auto& [y, delta, xl, xr] : events) {
      totalArea += tree.getCoveredWidth() * static_cast<long>(y - prevY);
      tree.add(xl, xr, delta);
      prevY = y;
    }
    return totalArea;
  }
};
