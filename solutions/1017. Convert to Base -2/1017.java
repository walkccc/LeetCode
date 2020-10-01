class Solution {
  public String baseNeg2(int N) {
    StringBuilder ans = new StringBuilder();

    while (N != 0) {
      ans.append(N & 1);
      N = -(N >> 1);
    }

    return ans.length() > 0 ? ans.reverse().toString() : "0";
  }
}