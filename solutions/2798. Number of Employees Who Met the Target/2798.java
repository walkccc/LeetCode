class Solution {
  public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
    return (int) Arrays.stream(hours).filter(hour -> hour >= target).count();
  }
}
