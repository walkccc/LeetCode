class Solution {
  public boolean escapeGhosts(int[][] ghosts, int[] target) {
    int ghostSteps = Integer.MAX_VALUE;

    for (int[] ghost : ghosts)
      ghostSteps = Math.min(ghostSteps, Math.abs(ghost[0] - target[0]) + Math.abs(ghost[1] - target[1]));

    return Math.abs(target[0]) + Math.abs(target[1]) < ghostSteps;
  }
}