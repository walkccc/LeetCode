class Solution {
  public List<Integer> findPeaks(int[] mountain) {
    List<Integer> ans = new ArrayList<>();
    for (int i = 1; i + 1 < mountain.length; ++i)
      if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
        ans.add(i);
    return ans;
  }
}
