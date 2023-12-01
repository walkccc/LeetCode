class Solution {
 public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = num / 2; i <= num; ++i)
      if (num == i + reversed(i))
        return true;
    return false;
  }

 private:
  int reversed(int num) {
    int ans = 0;
    while (num > 0) {
      ans = ans * 10 + num % 10;
      num /= 10;
    }
    return ans;
  }
};
