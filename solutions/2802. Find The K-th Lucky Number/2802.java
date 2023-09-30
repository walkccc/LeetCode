class Solution {
  public String kthLuckyNumber(int k) {
    StringBuilder sb = new StringBuilder();

    for (int i = k + 1; i > 0; i /= 2)
      sb.append((i & 1) == 1 ? '7' : '4');

    return sb.reverse().substring(1);
  }
}
