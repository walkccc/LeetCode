class Solution {
  public int[] getCoprimes(int[] nums, int[][] edges) {
    int[] ans = new int[nums.length];
    Arrays.fill(ans, -1);
    List<Integer>[] tree = new List[nums.length];
    // stacks[i] := (node, depth)s of nodes with value i
    Deque<Pair<Integer, Integer>>[] stacks = new Deque[kMax + 1];

    for (int i = 0; i < nums.length; ++i)
      tree[i] = new ArrayList<>();

    for (int i = 1; i <= kMax; ++i)
      stacks[i] = new ArrayDeque<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    dfs(tree, 0, /*prev=*/-1, /*depth=*/0, nums, stacks, ans);
    return ans;
  }

  private static final int kMax = 50;

  private void dfs(List<Integer>[] tree, int u, int prev, int depth, int[] nums,
                   Deque<Pair<Integer, Integer>>[] stacks, int[] ans) {
    ans[u] = getAncestor(u, stacks, nums);
    stacks[nums[u]].push(new Pair<>(u, depth));

    for (final int v : tree[u])
      if (v != prev)
        dfs(tree, v, u, depth + 1, nums, stacks, ans);

    stacks[nums[u]].pop();
  }

  private int getAncestor(int u, Deque<Pair<Integer, Integer>>[] stacks, int[] nums) {
    int maxNode = -1;
    int maxDepth = -1;
    for (int i = 1; i <= kMax; ++i)
      if (!stacks[i].isEmpty() && stacks[i].peek().getValue() > maxDepth && gcd(nums[u], i) == 1) {
        maxNode = stacks[i].peek().getKey();
        maxDepth = stacks[i].peek().getValue();
      }
    return maxNode;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
