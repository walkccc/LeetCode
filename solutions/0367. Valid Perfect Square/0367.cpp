class Solution {
 public:
  bool isPerfectSquare(int num) {
    long l = 1;
    long r = num;

    while (l < r) {
      const long m = l + (r - l) / 2;
      if (m < num / m)
        l = m + 1;
      else
        r = m;
    }

    return l * l == num;
  }
};