class Solution {
  public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
    List<List<Integer>> ans = new ArrayList<>();
    Set<Integer> queensSet = new HashSet<>();

    for (int[] queen : queens)
      queensSet.add(hash(queen[0], queen[1]));

    int[][] directions =
        new int[][] {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int[] d : directions)
      for (int i = king[0] + d[0], j = king[1] + d[1]; 0 <= i && i < 8 && 0 <= j && j < 8;
           i += d[0], j += d[1])
        if (queensSet.contains(hash(i, j))) {
          ans.add(Arrays.asList(i, j));
          break;
        }

    return ans;
  }

  private int hash(int i, int j) {
    return i * 8 + j;
  }
}
