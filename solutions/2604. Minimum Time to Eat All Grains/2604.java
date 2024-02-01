class Solution {
  public int minimumTime(int[] hens, int[] grains) {
    Arrays.sort(hens);
    Arrays.sort(grains);

    final int maxPosition = Math.max(Arrays.stream(hens).max().getAsInt(), //
                                     Arrays.stream(grains).max().getAsInt());
    final int minPosition = Math.min(Arrays.stream(hens).min().getAsInt(), //
                                     Arrays.stream(grains).min().getAsInt());
    int l = 0;
    int r = (int) (1.5 * (maxPosition - minPosition));

    while (l < r) {
      final int m = (int) ((l + (long) r) / 2);
      if (canEat(hens, grains, m))
        r = m;
      else
        l = m + 1;
    }

    return (int) l;
  }

  // Returns true if `hens` can eat all `grains` within `time`.
  private boolean canEat(int[] hens, int[] grains, int time) {
    int i = 0; // grains[i] := next grain to be ate
    for (final int hen : hens) {
      int rightMoves = time;
      if (grains[i] < hen) {
        // `hen` needs go back to eat `grains[i]`.
        final int leftMoves = hen - grains[i];
        if (leftMoves > time)
          return false;
        final int leftThenRight = time - 2 * leftMoves;
        final int rightThenLeft = (time - leftMoves) / 2;
        rightMoves = Math.max(0, Math.max(leftThenRight, rightThenLeft));
      }
      i = firstGreater(grains, hen + rightMoves);
      if (i == grains.length)
        return true;
    }
    return false;
  }

  private int firstGreater(int[] A, int target) {
    final int i = Arrays.binarySearch(A, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
