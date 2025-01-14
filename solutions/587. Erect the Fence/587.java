// Monotone Chain
class Solution {
  public int[][] outerTrees(int[][] trees) {
    Stack<int[]> hull = new Stack<>();

    Arrays.sort(trees,
                (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

    // Build the lower hull: left-to-right scan.
    for (int[] tree : trees) {
      while (hull.size() > 1 && cross(hull.peek(), hull.get(hull.size() - 2), tree) > 0)
        hull.pop();
      hull.push(tree);
    }
    hull.pop();

    // Build the upper hull: right-to-left scan.
    for (int i = trees.length - 1; i >= 0; --i) {
      while (hull.size() > 1 && cross(hull.peek(), hull.get(hull.size() - 2), trees[i]) > 0)
        hull.pop();
      hull.push(trees[i]);
    }

    // Remove the redundant elements from the stack.
    return new HashSet<>(hull).stream().toArray(int[][] ::new);
  }

  private int cross(int[] p, int[] q, int[] r) {
    return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
  }
}
