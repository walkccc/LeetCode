class Solution {
  public int[] distributeCandies(int candies, int num_people) {
    int[] ans = new int[num_people];
    long c = (long) candies;
    long n = (long) num_people;
    int rows = (int) (-n + Math.sqrt(n * n + 8 * n * n * c)) / (int) (2 * n * n);
    int accumN = rows * (rows - 1) * num_people / 2;

    for (int i = 0; i < n; ++i)
      ans[i] = accumN + rows * (i + 1);

    int givenCandies = (num_people * num_people * rows * rows + num_people * rows) / 2;
    candies -= givenCandies;

    for (int i = 0, lastGiven = rows * num_people + 1; candies > 0; ++i, ++lastGiven) {
      int actualGiven = Math.min(lastGiven, candies);
      candies -= actualGiven;
      ans[i] += actualGiven;
    }

    return ans;
  }
}
