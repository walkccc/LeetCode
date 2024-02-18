class Solution {
  public int minOperations(String s) {
    int cost10 = 0; // the cost to make s "1010"

    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) - '0' == i % 2)
        ++cost10;

    final int cost01 = s.length() - cost10; // the cost to make s "0101"
    return Math.min(cost10, cost01);
  }
}
