class Solution {
 public:
  int numberOfSteps(unsigned num) {
    if (num == 0)
      return 0;
    const int subtractSteps = popcount(num);
    const int divideSteps = 31 - __builtin_clz(num);
    return subtractSteps + divideSteps;
  }
};
