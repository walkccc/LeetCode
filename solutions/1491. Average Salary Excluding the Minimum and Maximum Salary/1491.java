class Solution {
  public double average(int[] salary) {
    final double sum = Arrays.stream(salary).sum();
    final int max = Arrays.stream(salary).max().getAsInt();
    final int min = Arrays.stream(salary).min().getAsInt();
    return (sum - max - min) / (salary.length - 2);
  }
}
