class Solution {
  public double average(int[] salary) {
    final double sum = Arrays.stream(salary).sum();
    final int mx = Arrays.stream(salary).max().getAsInt();
    final int mn = Arrays.stream(salary).min().getAsInt();
    return (sum - mx - mn) / (salary.length - 2);
  }
}
