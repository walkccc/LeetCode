class RangeModule {
 public:
  void addRange(int left, int right) {
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r) {            // no overlaps
      ranges[left] = right;  // add a new range
      return;
    }

    auto last = r;
    const int newLeft = min(l->first, left);
    const int newRight = max((--last)->second, right);
    ranges.erase(l, r);
    ranges[newLeft] = newRight;  // add a new range
  }

  bool queryRange(int left, int right) {
    auto it = ranges.upper_bound(left);
    return it != begin(ranges) && (--it)->second >= right;
  }

  void removeRange(int left, int right) {
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r)  // no overlaps
      return;

    auto last = r;
    const int newLeft = min(l->first, left);
    const int newRight = max((--last)->second, right);
    ranges.erase(l, r);
    // add new ranges if needed
    if (newLeft < left)
      ranges[newLeft] = left;
    if (right < newRight)
      ranges[right] = newRight;
  }

 private:
  using IT = map<int, int>::iterator;
  map<int, int> ranges;

  pair<IT, IT> getOverlapRanges(int left, int right) {
    // point to 1st element with second >= than left
    IT l = ranges.upper_bound(left);
    // point to 1st element with first > than right
    IT r = ranges.upper_bound(right);
    if (l != begin(ranges) && (--l)->second < left)
      ++l;
    return {l, r};
  }
};
