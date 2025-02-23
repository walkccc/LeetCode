class Solution {
  public List<List<Integer>> findRLEArray(int[][] encoded1, int[][] encoded2) {
    List<List<Integer>> ans = new ArrayList<>();
    int i = 0; // encoded1's index
    int j = 0; // encodes2's index

    while (i < encoded1.length && j < encoded2.length) {
      final int mult = encoded1[i][0] * encoded2[j][0];
      final int minFreq = Math.min(encoded1[i][1], encoded2[j][1]);
      if (!ans.isEmpty() && mult == ans.get(ans.size() - 1).get(0))
        ans.get(ans.size() - 1).set(1, ans.get(ans.size() - 1).get(1) + minFreq);
      else
        ans.add(Arrays.asList(mult, minFreq));
      encoded1[i][1] -= minFreq;
      encoded2[j][1] -= minFreq;
      if (encoded1[i][1] == 0)
        ++i;
      if (encoded2[j][1] == 0)
        ++j;
    }

    return ans;
  }
}
