class Solution {
  public List<Integer> mostVisited(int n, int[] rounds) {
    // 1. If start <= end, [start, end] is the most visited.
    //
    //      s --------- n
    // 1 -------------- n
    // 1 ------ e
    //
    // 2. If start > end, [1, end] and [start, n] are the most visited.
    //
    //             s -- n
    // 1 -------------- n
    // 1 ------ e
    final int start = rounds[0];
    final int end = rounds[rounds.length - 1];
    List<Integer> ans = new ArrayList<>();
    for (int i = 1; i <= n; ++i)
      if (start <= end) {
        if (start <= i && i <= end)
          ans.add(i);
      } else { // start > end
        if (i >= start || i <= end)
          ans.add(i);
      }
    return ans;
  }
}
