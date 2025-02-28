class Solution {
  public String kthLuckyNumber(int k) {
    StringBuilder sb = new StringBuilder();

    for (int i = k + 1; i > 0; i /= 2)
      sb.append(i % 2 == 0 ? '4' : '7');

    return sb.reverse().substring(1);
  }
}
