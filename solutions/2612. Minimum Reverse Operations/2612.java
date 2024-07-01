class Solution {
  public int[] minReverseOperations(int n, int p, int[] banned, int k) {
    Set<Integer> bannedSet = Arrays.stream(banned).boxed().collect(Collectors.toSet());
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    // unseen[i] := the unseen numbers that % 2 == i
    TreeSet<Integer>[] unseen = new TreeSet[2];
    unseen[0] = new TreeSet<>();
    unseen[1] = new TreeSet<>();

    for (int num = 0; num < n; ++num)
      if (num != p && !bannedSet.contains(num))
        unseen[num & 1].add(num);

    // Perform BFS from `p`.
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(p));
    ans[p] = 0;

    while (!q.isEmpty()) {
      final int u = q.poll();
      final int lo = Math.max(u - k + 1, k - 1 - u);
      final int hi = Math.min(u + k - 1, n - 1 - (u - (n - k)));
      // Choose the correct set of numbers.
      TreeSet<Integer> nums = unseen[lo & 1];
      for (Integer num = nums.ceiling(lo); num != null && num <= hi;) {
        ans[num] = ans[u] + 1;
        q.offer(num);
        nums.remove(num);
        num = nums.higher(num);
      }
    }

    return ans;
  }
}
