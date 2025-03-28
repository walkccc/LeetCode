class Solution {
  public int[][] sortTheStudents(int[][] score, int k) {
    Arrays.sort(score, Comparator.comparingInt(a -> - a[k]));
    return score;
  }
}
