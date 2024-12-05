class Solution {
  public int[] minOperations(String boxes) {
    int[] ans = new int[boxes.length()];

    for (int i = 0, count = 0, moves = 0; i < boxes.length(); ++i) {
      ans[i] += moves;
      count += boxes.charAt(i) == '1' ? 1 : 0;
      moves += count;
    }

    for (int i = boxes.length() - 1, count = 0, moves = 0; i >= 0; --i) {
      ans[i] += moves;
      count += boxes.charAt(i) == '1' ? 1 : 0;
      moves += count;
    }

    return ans;
  }
}
