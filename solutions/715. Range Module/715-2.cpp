class RangeModule {
 public:
  void addRange(int left, int right) {
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r) {            // There's no overlap.
      ranges[left] = right;  // Add a new range.
      return;
    }

    auto last = r;
    const int newLeft = min(l->first, left);
    const int newRight = max((--last)->second, right);
    ranges.erase(l, r);
    ranges[newLeft] = newRight;  // Add a new range.
  }

  bool queryRange(int left, int right) {
    auto it = ranges.upper_bound(left);
    return it != ranges.begin() && (--it)->second >= right;
  }

  void removeRange(int left, int right) {
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r)  // There's no overlap.
      return;

    auto last = r;
    const int newLeft = min(l->first, left);
    const int newRight = max((--last)->second, right);
    ranges.erase(l, r);
    // Add new ranges if needed.
    if (newLeft < left)
      ranges[newLeft] = left;
    if (right < newRight)
      ranges[right] = newRight;
  }

 private:
  using IT = map<int, int>::iterator;
  map<int, int> ranges;

  pair<IT, IT> getOverlapRanges(int left, int right) {
    // Point to the first element with `second` >= `left`.
    IT l = ranges.upper_bound(left);
    // Point to the first element with `first` > `right`.
    IT r = ranges.upper_bound(right);
    if (l != ranges.begin() && (--l)->second < left)
      ++l;
    return {l, r};
  }
};
