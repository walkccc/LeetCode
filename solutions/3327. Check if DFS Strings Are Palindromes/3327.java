class Solution {
  public boolean[] findAnswer(int[] parent, String s) {
    final int n = parent.length;
    boolean[] ans = new boolean[n];
    List<Integer>[] tree = new List[n];
    // start[i] := the start index of `dfsStr` of node i
    int[] start = new int[n];
    // end[i] := the end index of `dfsStr` of node i
    int[] end = new int[n];

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    StringBuilder dfsStr = new StringBuilder();

    for (int i = 1; i < n; ++i)
      tree[parent[i]].add(i);

    dfs(tree, 0, /*index=*/0, s, start, end, dfsStr);
    final String t = join('@' + dfsStr.toString() + '$', '#');
    final int[] p = manacher(t);

    for (int i = 0; i < n; ++i)
      ans[i] = isPalindrome(start[i], end[i], p);

    return ans;
  }

  // Returns the start index of the "DFS string" of u's next node.
  private int dfs(List<Integer>[] tree, int u, int index, final String s, int[] start, int[] end,
                  StringBuilder dfsStr) {
    start[u] = index;
    for (final int v : tree.get(u))
      index = dfs(tree, v, index, s, start, end, dfsStr);
    end[u] = index;
    dfsStr.append(s.charAt(u));
    return index + 1;
  }

  // Returns true if `dfsStr[s..e]` is a palindrome by using the precomputed
  // array `p` from the Manacher's algorithm.
  //
  // The precomputed array `p` is based on the string `t` with delimiters and
  // sentinels. Let `t = '#'.join('@' + dfsStr + '$')`. Then, the center of
  // `dfsStr` maps to `t[s + e + 2]` since `dfsStr[s]` maps to `t[2 * s + 2]`
  // and `dfsStr[e]` maps to `t[2 * e + 2]`. So, the center of `dfsStr` is
  // `t[(2 * s + 2 + 2 * e + 2) / 2] = t[s + e + 2]`.
  private boolean isPalindrome(int s, int e, int[] p) {
    final int length = e - s + 1;
    final int center = s + e + 2;
    return p[center] >= length;
  }

  // Returns an array `p` s.t. `p[i]` is the length of the longest palindrome
  // centered at `t[i]`, where `t` is a string with delimiters and sentinels.
  private int[] manacher(final String t) {
    int[] p = new int[t.length()];
    int center = 0;
    for (int i = 1; i < t.length() - 1; ++i) {
      int rightBoundary = center + p[center];
      int mirrorIndex = center - (i - center);
      if (rightBoundary > i)
        p[i] = Math.min(rightBoundary - i, p[mirrorIndex]);
      // Try to expand the palindrome centered at i.
      while (i + 1 + p[i] < t.length() && i - 1 - p[i] >= 0 &&
             t.charAt(i + 1 + p[i]) == t.charAt(i - 1 - p[i]))
        ++p[i];
      // If a palindrome centered at i expands past `rightBoundary`, adjust
      // the center based on the expanded palindrome.
      if (i + p[i] > rightBoundary) {
        center = i;
      }
    }
    return p;
  }

  private String join(final String s, char delimiter) {
    StringBuilder joined = new StringBuilder();
    for (int i = 0; i < s.length() - 1; ++i) {
      joined.append(s.charAt(i));
      joined.append(delimiter);
    }
    joined.append(s.charAt(s.length() - 1));
    return joined.toString();
  }
}
