class Solution {
  public boolean canReach(int[] arr, int start) {
    final int n = arr.length;
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(start));
    boolean[] seen = new boolean[n];

    while (!q.isEmpty()) {
      final int node = q.poll();

      if (arr[node] == 0)
        return true;
      if (seen[node])
        continue;

      // check available next steps
      if (node - arr[node] >= 0)
        q.offer(node - arr[node]);
      if (node + arr[node] < n)
        q.offer(node + arr[node]);

      seen[node] = true;
    }

    return false;
  }
}
