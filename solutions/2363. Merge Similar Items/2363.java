class Solution {
  public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
    final int kMax = 1000;
    List<List<Integer>> ans = new ArrayList<>();
    int[] count = new int[kMax + 1];

    for (int[] item : items1)
      count[item[0]] += item[1];

    for (int[] item : items2)
      count[item[0]] += item[1];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] > 0)
        ans.add(Arrays.asList(i, count[i]));

    return ans;
  }
}
