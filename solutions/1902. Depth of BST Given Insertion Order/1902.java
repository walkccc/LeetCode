class Solution {
  public int maxDepthBST(int[] order) {
    int ans = 1;
    TreeMap<Integer, Integer> valToDepth = new TreeMap<>();

    for (final int val : order) {
      Map.Entry<Integer, Integer> l = valToDepth.floorEntry(val);
      Map.Entry<Integer, Integer> r = valToDepth.ceilingEntry(val);
      final int leftDepth = l == null ? 0 : l.getValue();
      final int rightDepth = r == null ? 0 : r.getValue();
      final int depth = Math.max(leftDepth, rightDepth) + 1;
      ans = Math.max(ans, depth);
      valToDepth.put(val, depth);
    }

    return ans;
  }
}
