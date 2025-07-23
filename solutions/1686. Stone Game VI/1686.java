class Solution {
  public int stoneGameVI(int[] aliceValues, int[] bobValues) {
    final int n = aliceValues.length;
    int[][] values = new int[n][];

    for (int i = 0; i < n; ++i)
      values[i] = new int[] {aliceValues[i], bobValues[i]};

    Arrays.sort(values, Comparator.comparingInt(value -> - value[0] - value[1]));

    int a = 0;
    int b = 0;

    for (int i = 0; i < n; ++i)
      if (i % 2 == 0)
        a += values[i][0];
      else
        b += values[i][1];

    return Integer.compare(a, b);
  }
}
