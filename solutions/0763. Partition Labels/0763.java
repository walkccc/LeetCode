class Solution {
  public List<Integer> partitionLabels(String s) {
    List<Integer> ans = new ArrayList<>();
    int[] rightmost = new int[128];

    for (int i = 0; i < s.length(); ++i)
      rightmost[s.charAt(i)] = i;

    int l = 0; // First index of current running string
    int r = 0; // Right most so far

    for (int i = 0; i < s.length(); ++i) {
      r = Math.max(r, rightmost[s.charAt(i)]);
      if (r == i) {
        ans.add(i - l + 1);
        l = i + 1;
      }
    }

    return ans;
  }
}
