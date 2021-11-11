class Solution {
  public int minimumOperations(int[] nums, int start, int goal) {
    int ans = 0;
    Queue<Integer> q = new LinkedList<>(Arrays.asList(start));
    boolean[] seen = new boolean[1001];
    seen[start] = true;

    while (!q.isEmpty()) {
      ++ans;
      for (int size = q.size(); size > 0; --size) {
        final int x = q.poll();
        for (final int num : nums) {
          for (final int res : new int[] {x + num, x - num, x ^ num}) {
            if (res == goal)
              return ans;
            if (res < 0 || res > 1000 || seen[res])
              continue;
            seen[res] = true;
            q.offer(res);
          }
        }
      }
    }

    return -1;
  }
}
