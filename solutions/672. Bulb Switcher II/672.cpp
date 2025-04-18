class Solution {
 public:
  int flipLights(int n, int m) {
    n = min(n, 3);

    if (m == 0)
      return 1;
    if (m == 1)
      return vector{2, 3, 4}[n - 1];
    if (m == 2)
      return vector{2, 4, 7}[n - 1];

    return pow(2, n);
  }
};
