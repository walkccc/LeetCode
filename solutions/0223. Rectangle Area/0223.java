class Solution {
  public int computeArea(long A, long B, long C, long D, long E, long F, long G, long H) {
    final long x = Math.max(A, E) < Math.min(C, G) ? (Math.min(C, G) - Math.max(A, E)) : 0;
    final long y = Math.max(B, F) < Math.min(D, H) ? (Math.min(D, H) - Math.max(B, F)) : 0;
    return (int) ((C - A) * (D - B) + (G - E) * (H - F) - x * y);
  }
}
