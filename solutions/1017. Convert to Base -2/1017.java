class Solution {
  public String baseNeg2(int N) {
    StringBuilder sb = new StringBuilder();

    while (N != 0) {
      sb.append(N & 1);
      N = -(N >> 1);
    }

    return sb.length() > 0 ? sb.reverse().toString() : "0";
  }
}
