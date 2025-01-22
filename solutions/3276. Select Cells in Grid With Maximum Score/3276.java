class Solution {
  public int maxScore(List<List<Integer>> grid) {
    Map<Integer, Set<Integer>> numToIndices = new HashMap<>();
    for (int index = 0; index < grid.size(); ++index)
      for (final int num : grid.get(index)) {
        numToIndices.putIfAbsent(num, new HashSet<>());
        numToIndices.get(num).add(index);
      }
    int[][] mem = new int[numToIndices.size()][1 << grid.size()];
    return maxScore(new ArrayList<>(numToIndices.entrySet()), 0, 0, mem);
  }

  // Returns the maximum score by selecting numbers from numToIndices[i..],
  // where `mask` is the bitmask of the used row indices.
  private int maxScore(List<Map.Entry<Integer, Set<Integer>>> numToIndices, int i, int mask,
                       int[][] mem) {
    if (i == numToIndices.size())
      return 0;
    if (mem[i][mask] != 0)
      return mem[i][mask];
    // Skip numToIndices[i].getKey().
    int res = maxScore(numToIndices, i + 1, mask, mem);
    for (int index : numToIndices.get(i).getValue())
      if ((mask >> index & 1) == 0)
        // Take numToIndices[i].getKey().
        res = Math.max(res, numToIndices.get(i).getKey() +
                                maxScore(numToIndices, i + 1, mask | (1 << index), mem));
    return mem[i][mask] = res;
  }
}
