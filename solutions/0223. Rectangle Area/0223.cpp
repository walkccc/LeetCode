class Solution {
 public:
  int computeArea(long A, long B, long C, long D,
                  long E, long F, long G, long H) {
    const long x = max(A, E) < min(C, G) ? (min(C, G) - max(A, E)) : 0;
    const long y = max(B, F) < min(D, H) ? (min(D, H) - max(B, F)) : 0;
    return (C - A) * (D - B) + (G - E) * (H - F) - x * y;
  }
};
