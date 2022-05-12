class Solution {
  public int maxDepthBST(int[] order) {
    int ans = 1;
    TreeMap<Integer, Integer> map = new TreeMap<>(); // {val: depth}
    map.put(order[0], 1);

    for (int i = 1; i < order.length; ++i) {
      final int val = order[i];
      Map.Entry<Integer, Integer> l = map.floorEntry(val);   // max <= val
      Map.Entry<Integer, Integer> r = map.ceilingEntry(val); // min >= val
      final int leftDepth = l == null ? 0 : l.getValue();
      final int rightDepth = r == null ? 0 : r.getValue();
      final int depth = Math.max(leftDepth, rightDepth) + 1;
      ans = Math.max(ans, depth);
      map.put(val, depth);
    }

    return ans;
  }
}
