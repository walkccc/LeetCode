class Solution {
 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    // The rook is in the same row as the queen.
    if (a == e)
      // The bishop blocks the rook or not.
      return (c == a && (b < d && d < f || b > d && d > f)) ? 2 : 1;
    // The rook is in the same column as the queen.
    if (b == f)
      // The bishop blocks the rook or not.
      return (d == f && (a < c && c < e || a > c && c > e)) ? 2 : 1;
    // The bishop is in the same up-diagonal as the queen.
    if (c + d == e + f)
      // The rook blocks the bishop or not.
      return (a + b == c + d && (c < a && a < e || c > a && a > e)) ? 2 : 1;
    // The bishop is in the same down-diagonal as the queen.
    if (c - d == e - f)
      // The rook blocks the bishop or not.
      return (a - b == c - d && (c < a && a < e || c > a && a > e)) ? 2 : 1;
    // The rook can always get the green in two steps.
    return 2;
  }
};
