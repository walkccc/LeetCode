class Solution {
  public int maxVacationDays(int[][] flights, int[][] days) {
    int[][] mem = new int[days.length][days[0].length];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MIN_VALUE));
    return maxVacationDays(flights, days, 0, 0, mem);
  }

  // Returns the number of vacations that can be taken from the i-th city and
  // the k-th week.
  private int maxVacationDays(int[][] flights, int[][] days, int i, int k, int[][] mem) {
    if (k == days[0].length)
      return 0;
    if (mem[i][k] != Integer.MIN_VALUE)
      return mem[i][k];

    // Stay at the j-th city or fly from the i-th city to the j-th city.
    for (int j = 0; j < flights.length; j++)
      if (j == i || flights[i][j] == 1)
        mem[i][k] = Math.max(mem[i][k], days[j][k] + maxVacationDays(flights, days, j, k + 1, mem));

    return mem[i][k];
  }
}
