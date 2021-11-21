class Solution {
  public boolean isReflected(int[][] points) {
    int minX = Integer.MAX_VALUE;
    int maxX = Integer.MIN_VALUE;
    Set<String> seen = new HashSet<>();

    for (int[] p : points) {
      minX = Math.min(minX, p[0]);
      maxX = Math.max(maxX, p[0]);
      seen.add(p[0] + "," + p[1]);
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
