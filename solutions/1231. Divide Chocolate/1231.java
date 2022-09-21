class Solution {
  public int maximizeSweetness(int[] sweetness, int k) {
    int l = sweetness.length / (k + 1);
    int r = Arrays.stream(sweetness).sum() / (k + 1);

    while (l < r) {
      final int m = (l + r) / 2;
      if (canEat(sweetness, k, m))
        l = m + 1;
      else
        r = m;
    }

    return canEat(sweetness, k, l) ? l : l - 1;
  }

  // true if you can eat m sweetness (min sweetness of each piece)
  private boolean canEat(int[] sweetness, int k, int m) {
    int pieces = 0;
    int sum = 0; // running sum

    for (final int s : sweetness) {
      sum += s;
      if (sum >= m) {
        if (++pieces > k)
          return true;
        sum = 0;
      }
    }

    return false;
  }
}
