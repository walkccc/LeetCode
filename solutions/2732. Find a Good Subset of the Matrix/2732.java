class Solution {
  public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
    final int kMaxBit = 32;
    Map<Integer, Integer> maskToIndex = new HashMap<>();

    for (int i = 0; i < grid.length; ++i) {
      final int mask = getMask(grid[i]);
      if (mask == 0)
        return List.of(i);
      for (int prevMask = 1; prevMask < kMaxBit; ++prevMask)
        if ((mask & prevMask) == 0 && maskToIndex.containsKey(prevMask))
          return List.of(maskToIndex.get(prevMask), i);
      maskToIndex.put(mask, i);
    }

    return new ArrayList<>();
  }

  private int getMask(int[] row) {
    int mask = 0;
    for (int i = 0; i < row.length; ++i)
      if (row[i] == 1)
        mask |= 1 << i;
    return mask;
  }
}
