class Solution {
  public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
    if (Arrays.stream(tiles).anyMatch(tile -> tile[1] - tile[0] + 1 >= carpetLen))
      return carpetLen;

    int ans = 0;
    List<Integer> starts = new ArrayList<>();
    int[] prefix = new int[tiles.length + 1];

    Arrays.sort(tiles, (a, b) -> a[0] - b[0]);

    for (int[] tile : tiles)
      starts.add(tile[0]);

    for (int i = 0; i < tiles.length; ++i) {
      final int length = tiles[i][1] - tiles[i][0] + 1;
      prefix[i + 1] = prefix[i] + length;
    }

    for (int i = 0; i < tiles.length; ++i) {
      final int s = tiles[i][0];
      final int carpetEnd = s + carpetLen - 1;
      final int endIndex = firstGreater(starts, carpetEnd) - 1;
      final int notCover = Math.max(0, tiles[endIndex][1] - carpetEnd);
      ans = Math.max(ans, prefix[endIndex + 1] - prefix[i] - notCover);
    }

    return ans;
  }

  private int firstGreater(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
