class RangeModule {
 public:
  void addRange(int left, int right) {
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r) {            // No overlaps
      ranges[left] = right;  // Add a new range
      return;
    }

    auto last = r;
    const int newLeft = min(l->first, left);
    const int newRight = max((--last)->second, right);
    ranges.erase(l, r);
    ranges[newLeft] = newRight;  // Add a new range
  }

  bool queryRange(int left, int right) {
    auto it = ranges.upper_bound(left);
    return it != ranges.begin() && (--it)->second >= right;
  }

  void removeRange(int left, int right) {
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r)  // No overlaps
      return;

    auto last = r;
    const int newLeft = min(l->first, left);
    const int newRight = max((--last)->second, right);
    ranges.erase(l, r);
    // Add new ranges if needed
    if (newLeft < left)
      ranges[newLeft] = left;
    if (right < newRight)
      ranges[right] = newRight;
  }

 private:
  using IT = map<int, int>::iterator;
  map<int, int> ranges;

  pair<IT, IT> getOverlapRanges(int left, int right) {
    // Point to 1st element with second >= than left
    IT l = ranges.upper_bound(left);
    // Point to 1st element with first > than right
    IT r = ranges.upper_bound(right);
    if (l != ranges.begin() && (--l)->second < left)
      ++l;
    return {l, r};
  }
};
