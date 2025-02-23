class Solution {
 public:
  int minimumTime(vector<int>& hens, vector<int>& grains) {
    ranges::sort(hens);
    ranges::sort(grains);

    const int maxPosition = max(ranges::max(hens), ranges::max(grains));
    const int minPosition = min(ranges::min(hens), ranges::min(grains));
    int l = 0;
    int r = 1.5 * (maxPosition - minPosition);

    while (l < r) {
      const int m = (l + static_cast<long>(r)) / 2;
      if (canEat(hens, grains, m))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns true if `hens` can eat all `grains` within `time`.
  bool canEat(const vector<int>& hens, const vector<int>& grains, int time) {
    int i = 0;  // grains[i] := next grain to be ate
    for (const int hen : hens) {
      int moves = time;
      if (grains[i] < hen) {
        // `hen` needs go back to eat `grains[i]`.
        const int leftMoves = hen - grains[i];
        if (leftMoves > time)
          return false;
        const int leftThenRight = time - 2 * leftMoves;
        const int rightThenLeft = (time - leftMoves) / 2;
        moves = max({0, leftThenRight, rightThenLeft});
      }
      i = ranges::upper_bound(grains, hen + moves) - grains.begin();
      if (i == grains.size())
        return true;
    }
    return false;
  }
};
