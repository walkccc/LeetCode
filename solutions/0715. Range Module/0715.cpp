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
    const auto [l, r] = getOverlapRanges(left, right);
    if (l == r)  // no overlaps
      return false;
    return l->first <= left && right <= l->second;
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
  map<int, int> ranges;

  typedef map<int, int>::iterator IT;
  pair<IT, IT> getOverlapRanges(int left, int right) {
    IT l = ranges.upper_bound(left);   // point to 1st element >= than left
    IT r = ranges.upper_bound(right);  // point to 1st element > than right
    if (l != begin(ranges))
      if ((--l)->second < left)
        ++l;
    return {l, r};
  }
};
