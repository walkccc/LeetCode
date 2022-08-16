class Solution {
  public List<Integer> partitionLabels(String S) {
    List<Integer> ans = new ArrayList<>();
    int[] rightmost = new int[128];

    for (int i = 0; i < S.length(); ++i)
      rightmost[S.charAt(i)] = i;

    int l = 0; // first index of current running string
    int r = 0; // right most so far

    for (int i = 0; i < S.length(); ++i) {
      r = Math.max(r, rightmost[S.charAt(i)]);
      if (r == i) {
        ans.add(i - l + 1);
        l = i + 1;
      }
    }

    return ans;
  }
}
