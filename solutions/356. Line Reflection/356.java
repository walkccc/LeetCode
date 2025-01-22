class Solution {
  public boolean isReflected(int[][] points) {
    int minX = Integer.MAX_VALUE;
    int maxX = Integer.MIN_VALUE;
    Set<String> seen = new HashSet<>();

    for (int[] p : points) {
      final int x = p[0];
      final int y = p[1];
      minX = Math.min(minX, x);
      maxX = Math.max(maxX, x);
      seen.add(x + "," + y);
    }

    final int sum = minX + maxX;
    // (leftX + rightX) / 2 = (minX + maxX) / 2
    //  leftX = minX + maxX - rightX
    // rightX = minX + maxX - leftX

    for (int[] p : points)
      if (!seen.contains(sum - p[0] + "," + p[1]))
        return false;

    return true;
  }
}
