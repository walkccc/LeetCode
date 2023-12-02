class Solution {
  public List<Integer> goodDaysToRobBank(int[] security, int time) {
    final int n = security.length;
    List<Integer> ans = new ArrayList<>();
    // dec[i] := the number of continuous decreasing numbers before i
    int[] dec = new int[n];
    // inc[i] := the number of continuous increasing numbers after i
    int[] inc = new int[n];

    for (int i = 1; i < n; ++i)
      if (security[i - 1] >= security[i])
        dec[i] = dec[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
      if (security[i] <= security[i + 1])
        inc[i] = inc[i + 1] + 1;

    for (int i = 0; i < n; ++i)
      if (dec[i] >= time && inc[i] >= time)
        ans.add(i);

    return ans;
  }
}
