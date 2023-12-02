class Solution {
  public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
    List<Integer> ans = new ArrayList<>();
    // tail[i] := the minimum tail of all the increasing subsequences with
    // length i + 1
    // It's easy to see that tail must be an increasing array
    List<Integer> tail = new ArrayList<>();

    for (final int obstacle : obstacles)
      if (tail.isEmpty() || obstacle >= tail.get(tail.size() - 1)) {
        tail.add(obstacle);
        ans.add(tail.size());
      } else {
        final int index = firstGreater(tail, obstacle);
        tail.set(index, obstacle);
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
