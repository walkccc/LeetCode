class Solution {
  public List<Integer> mostVisited(int n, int[] rounds) {
    // Case 1: if start <= end, [start, end] are most visited
    //
    //      s --------- n
    // 1 -------------- n
    // 1 ------ e
    //
    // Case 2: if start > end, [1, end] and [start, n] are most visited
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
