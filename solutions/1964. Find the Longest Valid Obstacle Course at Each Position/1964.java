class Solution {
  // Similar to 300. Longest Increasing Subsequence
  public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
    List<Integer> ans = new ArrayList<>();
    // tails[i] := the minimum tail of all the increasing subsequences with
    // length i + 1
    List<Integer> tails = new ArrayList<>();

    for (final int obstacle : obstacles)
      if (tails.isEmpty() || obstacle >= tails.get(tails.size() - 1)) {
        tails.add(obstacle);
        ans.add(tails.size());
      } else {
        final int index = firstGreater(tails, obstacle);
        tails.set(index, obstacle);
        ans.add(index + 1);
      }

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private int firstGreater(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
