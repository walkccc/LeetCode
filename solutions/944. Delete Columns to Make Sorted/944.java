class Solution {
  public int minDeletionSize(String[] strs) {
    int ans = 0;

    for (int j = 0; j < strs[0].length(); ++j)
      for (int i = 0; i + 1 < strs.length; ++i)
        if (strs[i].charAt(j) > strs[i + 1].charAt(j)) {
          ++ans;
          break;
        }

    return ans;
  }
}
