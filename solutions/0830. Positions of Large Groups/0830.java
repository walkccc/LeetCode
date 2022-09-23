class Solution {
  public List<List<Integer>> largeGroupPositions(String S) {
    final int n = S.length();
    List<List<Integer>> ans = new ArrayList<>();

    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && S.charAt(j) == S.charAt(i))
        ++j;
      if (j - i >= 3)
        ans.add(Arrays.asList(i, j - 1));
    }

    return ans;
  }
}
