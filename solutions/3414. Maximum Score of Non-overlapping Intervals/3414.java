class Solution {
  public int[] maximumWeight(List<List<Integer>> intervals) {
    // Convert input to Interval objects
    List<Interval> indexedIntervals = new ArrayList<>();
    for (int i = 0; i < intervals.size(); ++i) {
      List<Integer> interval = intervals.get(i);
      indexedIntervals.add(new Interval(interval.get(0), interval.get(1), interval.get(2), i));
    }
    indexedIntervals.sort(Comparator.comparingInt(Interval::left));
    T[][] memo = new T[indexedIntervals.size()][5];
    return dp(indexedIntervals, memo, 0, 4).selected.stream().mapToInt(Integer::intValue).toArray();
  }

  private record T(long weight, List<Integer> selected) {}
  private record Interval(int left, int right, int weight, int originalIndex) {}

  private T dp(List<Interval> intervals, T[][] memo, int i, int quota) {
    if (i == intervals.size() || quota == 0)
      return new T(0, List.of());
    if (memo[i][quota] != null)
      return memo[i][quota];

    T skip = dp(intervals, memo, i + 1, quota);

    Interval interval = intervals.get(i);
    final int j = findFirstGreater(intervals, i + 1, interval.right);
    T nextRes = dp(intervals, memo, j, quota - 1);

    List<Integer> newSelected = new ArrayList<>(nextRes.selected);
    newSelected.add(interval.originalIndex);
    Collections.sort(newSelected);
    T pick = new T(interval.weight + nextRes.weight, newSelected);
    return memo[i][quota] =
               (pick.weight > skip.weight ||
                (pick.weight == skip.weight && compareLists(pick.selected, skip.selected) < 0))
                   ? pick
                   : skip;
  }

  // Binary searches the first interval that starts after `rightBoundary`.
  private int findFirstGreater(List<Interval> intervals, int startFrom, int rightBoundary) {
    int l = startFrom;
    int r = intervals.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (intervals.get(m).left > rightBoundary)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

  // Compares two lists of integers lexicographically.
  private int compareLists(List<Integer> list1, List<Integer> list2) {
    final int minSize = Math.min(list1.size(), list2.size());
    for (int i = 0; i < minSize; ++i) {
      final int comparison = Integer.compare(list1.get(i), list2.get(i));
      if (comparison != 0)
        return comparison;
    }
    return Integer.compare(list1.size(), list2.size());
  }
}
