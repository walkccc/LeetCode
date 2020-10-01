class Solution {
 public:
  bool judgeSquareSum(int c) {
    long l = 0;
    long r = sqrt(c);

    while (l <= r) {
      const long sum = l * l + r * r;
      if (sum == c) return true;
      if (sum < c)
        ++l;
      else
        --r;
    }

    return false;
  }
};