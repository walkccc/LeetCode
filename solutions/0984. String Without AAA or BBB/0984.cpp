class Solution {
 public:
  string strWithout3a3b(int A, int B, char a = 'a', char b = 'b') {
    if (A < B)
      return strWithout3a3b(B, A, b, a);
    if (B == 0)
      return string(min(A, 2), a);

    const int useA = min(A, 2);
    const int useB = (A - useA >= B) ? 1 : 0;
    return string(useA, a) + string(useB, b) +
           strWithout3a3b(A - useA, B - useB, a, b);
  }
};
