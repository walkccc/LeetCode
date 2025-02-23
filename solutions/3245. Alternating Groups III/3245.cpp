struct SegmentTree {
 public:
  explicit SegmentTree(int n)
      : n(n), treeIntervalCounts(4 * n), treeIntervalLengths(4 * n) {}

  // Adds val to intervalCounts[i] and updates intervalLengths[i] accordingly.
  void add(int i, int val) {
    add(0, 0, n - 1, i, val);
  }

  // Returns sum(intervalCounts[i..n - 1]).
  int queryIntervalCounts(int i) const {
    return query(treeIntervalCounts, 0, 0, n - 1, i, n - 1);
  }

  // Returns sum(intervalLengths[i..n - 1]).
  int queryIntervalLengths(int i) const {
    return query(treeIntervalLengths, 0, 0, n - 1, i, n - 1);
  }

 private:
  const int n;
  vector<int> treeIntervalCounts;
  vector<int> treeIntervalLengths;

  void add(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == hi) {
      treeIntervalCounts[treeIndex] += val;
      treeIntervalLengths[treeIndex] = treeIntervalCounts[treeIndex] * i;
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      add(2 * treeIndex + 1, lo, mid, i, val);
    else
      add(2 * treeIndex + 2, mid + 1, hi, i, val);
    treeIntervalCounts[treeIndex] =
        merge(treeIntervalCounts[2 * treeIndex + 1],
              treeIntervalCounts[2 * treeIndex + 2]);
    treeIntervalLengths[treeIndex] =
        merge(treeIntervalLengths[2 * treeIndex + 1],
              treeIntervalLengths[2 * treeIndex + 2]);
  }

  int query(const vector<int>& tree, int treeIndex, int lo, int hi, int i,
            int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return 0;
    const int mid = (lo + hi) / 2;
    return merge(query(tree, treeIndex * 2 + 1, lo, mid, i, j),
                 query(tree, treeIndex * 2 + 2, mid + 1, hi, i, j));
  }

  int merge(int left, int right) const {
    return left + right;
  }
};

class Solution {
 public:
  vector<int> numberOfAlternatingGroups(vector<int>& colors,
                                        vector<vector<int>>& queries) {
    const int n = colors.size();
    vector<int> ans;
    vector<int> arr{colors};
    SegmentTree tree(2 * n - 1);
    set<pair<int, int>> intervals;

    arr.insert(arr.end(), colors.begin(), colors.end());

    // Insert all intervals, each of them is an alternating sequence.
    int start = 0;
    for (int i = 1; i < 2 * n - 1; ++i)
      if (arr[i] == arr[i - 1]) {
        insert(intervals, {start, i - 1}, tree, n);
        start = i;
      }
    insert(intervals, {start, 2 * n - 2}, tree, n);

    for (const vector<int>& query : queries)
      if (query[0] == 1) {
        const int sz = query[1];
        const pair<int, int>& intervalWithN = findInterval(intervals, n);
        const int numAlternatingGroups =
            getNumAlternatingGroups(sz, intervalWithN, tree, n);
        ans.push_back(numAlternatingGroups);
      } else {
        const int index = query[1];
        const int color = query[2];
        if (arr[index] == color)
          continue;
        update(intervals, index, color, arr, tree, n);
        if (index < n - 1)
          update(intervals, index + n, color, arr, tree, n);
      }

    return ans;
  }

 private:
  // Returns the number of alternating groups of size `sz`.
  int getNumAlternatingGroups(int sz, const pair<int, int>& intervalWithN,
                              const SegmentTree& tree, int n) {
    const int numIntervals = tree.queryIntervalCounts(sz);
    const int sumIntervals = tree.queryIntervalLengths(sz);
    // The number of alternating groups for an interval is |interval| - sz + 1.
    // Therefore, the number of alternating groups for all intervals is
    //   sum(|intervals[i]| - sz + 1)
    // = sum(|intervals[i]) - numIntervals * sz + numIntervals
    const int numAlternatingGroups =
        sumIntervals - numIntervals * sz + numIntervals;
    // We need to check if the interval (l, r) contains n, and if it does, we
    // need to adjust the number of alternating groups to avoid duplicates.
    const auto& [l, r] = intervalWithN;
    // 1. For an interval with l >= n, it wasn't being considered in `insert`
    // and `remove`.
    // 2. For an interval with r - l + 1 < sz, it's impossible to form a group
    // of size `sz`.
    if (l >= n || r - l + 1 < sz)
      return numAlternatingGroups;
    // 3. For an interval with r >= n, it's possible to duplicately count the
    // groups starting from n.
    if (r >= n) {  // l < n && r - 1 + 1 >= sz
      // Groups starting from [l..n) are non-duplicately counted.
      const int nonDuplicateGroups = n - l;
      // The number of groups of size `sz` in the interval [l..r].
      const int numGroups = (r - l + 1) - sz + 1;
      return numAlternatingGroups - max(0, numGroups - nonDuplicateGroups);
    }
    return numAlternatingGroups;
  }

  // Inserts an interval into `intervals` and updates `tree`.
  void insert(set<pair<int, int>>& intervals, const pair<int, int>& interval,
              SegmentTree& tree, int n) {
    intervals.insert(interval);
    if (interval.first < n)
      tree.add(interval.second - interval.first + 1, 1);
  }

  // Removes an interval from `intervals` and updates `tree`.
  void remove(set<pair<int, int>>& intervals, const pair<int, int>& interval,
              SegmentTree& tree, int n) {
    intervals.erase(interval);
    if (interval.first < n)
      tree.add(interval.second - interval.first + 1, -1);
  }

  // Returns the interval containing the target.
  pair<int, int> findInterval(const set<pair<int, int>>& intervals,
                              int target) {
    auto it = intervals.upper_bound({target, INT_MAX});
    return (*--it);
  }

  // Updates the color of the index-th element in `arr` and updates `intervals`
  // and `tree`.
  void update(set<pair<int, int>>& intervals, int index, int color,
              vector<int>& arr, SegmentTree& tree, int n) {
    arr[index] = color;

    const pair<int, int> intervalWithIndex = findInterval(intervals, index);
    remove(intervals, intervalWithIndex, tree, n);
    auto [start, end] = intervalWithIndex;

    // interval [s..i - 1|i|i + 1..e]
    //    index           ^
    if (start < index && index < end) {
      insert(intervals, {start, index - 1}, tree, n);
      insert(intervals, {index, index}, tree, n);
      insert(intervals, {index + 1, end}, tree, n);
      return;
    }

    // interval [s|s + 1..e]
    //    index  ^
    if (start == index && index < end)
      insert(intervals, {start + 1, end}, tree, n);

    // interval [s..e - 1|e]
    //    index           ^
    if (start < index && index == end)
      insert(intervals, {start, end - 1}, tree, n);

    start = index;
    end = index;
    vector<pair<int, int>> intervalsToRemove;

    auto it = intervals.upper_bound({index, INT_MAX});

    for (auto lit = it; lit != intervals.begin();) {
      --lit;
      if (arr[lit->second] == arr[start])  // [..lit->second|start..]
        break;
      intervalsToRemove.push_back(*lit);
      start = lit->first;
    }

    for (auto rit = it; rit != intervals.end(); ++rit) {
      if (arr[rit->first] == arr[end])  // [..end|rit->first..]
        break;
      intervalsToRemove.push_back(*rit);
      end = rit->second;
    }

    for (const pair<int, int>& interval : intervalsToRemove)
      remove(intervals, interval, tree, n);

    insert(intervals, {start, end}, tree, n);
  }
};
