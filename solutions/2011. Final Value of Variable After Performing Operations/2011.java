class Solution {
  public int finalValueAfterOperations(String[] operations) {
    int ans = 0;

    for (final String op : operations)
      ans += op.charAt(1) == '+' ? 1 : -1;

    return ans;
  }
}
