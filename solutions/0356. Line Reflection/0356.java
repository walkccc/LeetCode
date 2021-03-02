class Solution {
  public boolean isReflected(int[][] points) {
    int minX = Integer.MAX_VALUE;
    int maxX = Integer.MIN_VALUE;
    Set<String> seen = new HashSet<>();

    for (int[] point : points) {
      minX = Math.min(minX, point[0]);
      maxX = Math.max(maxX, point[0]);
      seen.add(point[0] + "," + point[1]);
    }

    final int sum = minX + maxX;
    // (leftX + rightX) / 2 = (minX + maxX) / 2
    //  leftX = minX + maxX - rightX
    // rightX = minX + maxX - leftX

    for (int[] point : points)
      if (!seen.contains(sum - point[0] + "," + point[1]))
        return false;

    return true;
  }
}
