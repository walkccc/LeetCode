class Solution {
  public int maxPathLength(int[][] coordinates, int k) {
    final int xk = coordinates[k][0];
    final int yk = coordinates[k][1];
    List<int[]> leftCoordinates = new ArrayList<>();
    List<int[]> rightCoordinates = new ArrayList<>();

    for (int[] coordinate : coordinates) {
      final int x = coordinate[0];
      final int y = coordinate[1];
      if (x < xk && y < yk)
        leftCoordinates.add(new int[] {x, y});
      else if (x > xk && y > yk)
        rightCoordinates.add(new int[] {x, y});
    }

    return 1 + lengthOfLIS(leftCoordinates) + lengthOfLIS(rightCoordinates);
  }

  // Similar to 300. Longest Increasing Subsequence
  private int lengthOfLIS(List<int[]> coordinates) {
    coordinates.sort(
        (a, b) -> a[0] == b[0] ? Integer.compare(b[1], a[1]) : Integer.compare(a[0], b[0]));
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    List<Integer> tails = new ArrayList<>();
    for (int[] coordinate : coordinates) {
      final int y = coordinate[1];
      if (tails.isEmpty() || y > tails.get(tails.size() - 1))
        tails.add(y);
      else
        tails.set(firstGreaterEqual(tails, y), y);
    }
    return tails.size();
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
  }
}
