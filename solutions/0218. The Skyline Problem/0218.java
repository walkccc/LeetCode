class Solution {
  public List<List<Integer>> getSkyline(int[][] buildings) {
    final int n = buildings.length;
    if (n == 0)
      return new ArrayList<>();
    if (n == 1) {
      final int left = buildings[0][0];
      final int right = buildings[0][1];
      final int height = buildings[0][2];
      List<List<Integer>> ans = new ArrayList<>();
      ans.add(new ArrayList<>(Arrays.asList(left, height)));
      ans.add(new ArrayList<>(Arrays.asList(right, 0)));
      return ans;
    }

    List<List<Integer>> leftSkyline = getSkyline(Arrays.copyOfRange(buildings, 0, n / 2));
    List<List<Integer>> rightSkyline = getSkyline(Arrays.copyOfRange(buildings, n / 2, n));
    return merge(leftSkyline, rightSkyline);
  }

  private List<List<Integer>> merge(List<List<Integer>> left, List<List<Integer>> right) {
    List<List<Integer>> ans = new ArrayList<>();
    int i = 0; // left's index
    int j = 0; // right's index
    int leftY = 0;
    int rightY = 0;

    while (i < left.size() && j < right.size())
      // choose the point with smaller x
      if (left.get(i).get(0) < right.get(j).get(0)) {
        leftY = left.get(i).get(1); // update the ongoing leftY
        addPoint(ans, left.get(i).get(0), Math.max(left.get(i++).get(1), rightY));
      } else {
        rightY = right.get(j).get(1); // update the ongoing rightY
        addPoint(ans, right.get(j).get(0), Math.max(right.get(j++).get(1), leftY));
      }

    while (i < left.size())
      addPoint(ans, left.get(i).get(0), left.get(i++).get(1));

    while (j < right.size())
      addPoint(ans, right.get(j).get(0), right.get(j++).get(1));

    return ans;
  }

  private void addPoint(List<List<Integer>> ans, int x, int y) {
    if (!ans.isEmpty() && ans.get(ans.size() - 1).get(0) == x) {
      ans.get(ans.size() - 1).set(1, y);
      return;
    }
    if (!ans.isEmpty() && ans.get(ans.size() - 1).get(1) == y)
      return;
    ans.add(new ArrayList<>(Arrays.asList(x, y)));
  }
}
