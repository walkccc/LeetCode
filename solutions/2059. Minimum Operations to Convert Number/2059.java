class Solution {
  public int minimumOperations(int[] nums, int start, int goal) {
    Queue<Integer> q = new ArrayDeque<>(List.of(start));
    boolean[] seen = new boolean[1001];
    seen[start] = true;

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int x = q.poll();
        for (final int num : nums) {
          for (final int res : new int[] {x + num, x - num, x ^ num}) {
            if (res == goal)
              return step;
            if (res < 0 || res > 1000 || seen[res])
              continue;
            seen[res] = true;
            q.offer(res);
          }
        }
      }

    return -1;
  }
}
