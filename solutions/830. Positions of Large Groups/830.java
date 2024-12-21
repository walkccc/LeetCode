class Solution {
  public List<List<Integer>> largeGroupPositions(String s) {
    final int n = s.length();
    List<List<Integer>> ans = new ArrayList<>();

    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && s.charAt(j) == s.charAt(i))
        ++j;
      if (j - i >= 3)
        ans.add(Arrays.asList(i, j - 1));
    }

    return ans;
  }
}
