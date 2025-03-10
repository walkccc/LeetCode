class Solution {
  public boolean escapeGhosts(int[][] ghosts, int[] target) {
    final int d = Math.abs(target[0]) + Math.abs(target[1]);

    for (int[] ghost : ghosts)
      if (d >= Math.abs(ghost[0] - target[0]) + Math.abs(ghost[1] - target[1]))
        return false;

    return true;
  }
}
