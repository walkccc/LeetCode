class Solution {
  public int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y)
      return y - x;

    Queue<Integer> q = new ArrayDeque<>(List.of(x));
    Set<Integer> seen = new HashSet<>();

    for (int ans = 0; !q.isEmpty(); ++ans) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int num = q.poll();
        if (num == y)
          return ans;
        if (seen.contains(num))
          continue;
        seen.add(num);
        if (num % 11 == 0)
          q.offer(num / 11);
        if (num % 5 == 0)
          q.offer(num / 5);
        q.offer(num - 1);
        q.offer(num + 1);
      }
    }

    throw new IllegalArgumentException();
  }
}
