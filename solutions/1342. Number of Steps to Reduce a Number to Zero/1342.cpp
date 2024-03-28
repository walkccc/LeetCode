class Solution {
 public:
  int numberOfSteps(int num) {
    if (num == 0)
      return 0;
    const int subtractSteps = __builtin_popcount(num);
    const int divideSteps = 31 - __builtin_clz(num);
    return subtractSteps + divideSteps;
  }
};
