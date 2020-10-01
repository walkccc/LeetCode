class Solution {
  public int nthUglyNumber(int n) {
    List<Integer> uglyNums = new ArrayList<>();
    uglyNums.add(1);
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    while (uglyNums.size() < n) {
      final int next2 = uglyNums.get(i2) * 2;
      final int next3 = uglyNums.get(i3) * 3;
      final int next5 = uglyNums.get(i5) * 5;
      final int next = Math.min(next2, Math.min(next3, next5));
      if (next == next2)
        ++i2;
      if (next == next3)
        ++i3;
      if (next == next5)
        ++i5;
      uglyNums.add(next);
    }

    return uglyNums.get(uglyNums.size() - 1);
  }
}