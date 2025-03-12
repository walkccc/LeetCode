class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> uglyNums{1};
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    while (uglyNums.size() < n) {
      const int next2 = uglyNums[i2] * 2;
      const int next3 = uglyNums[i3] * 3;
      const int next5 = uglyNums[i5] * 5;
      const int next = min({next2, next3, next5});
      if (next == next2)
        ++i2;
      if (next == next3)
        ++i3;
      if (next == next5)
        ++i5;
      uglyNums.push_back(next);
    }

    return uglyNums.back();
  }
};
