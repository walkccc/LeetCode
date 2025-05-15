class Solution {
  public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    final int minStep = Math.max(Math.abs(sx - fx), Math.abs(sy - fy));
    return minStep == 0 ? t != 1 : minStep <= t;
  }
}
