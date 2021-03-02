class Solution {
  public int shipWithinDays(int[] weights, int D) {
    int l = Arrays.stream(weights).max().getAsInt();
    int r = Arrays.stream(weights).sum();

    while (l < r) {
      int m = l + (r - l) / 2;
      int day = 1;
      int capacity = 0;
      for (int weight : weights) {
        if (capacity + weight > m) {
          ++day;
          capacity = weight;
        } else
          capacity += weight;
      }
      if (day <= D)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
}
