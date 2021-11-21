class Solution {
 public:
  bool isUgly(int num) {
    if (num == 0)
      return false;

    for (const int prime : {2, 3, 5})
      while (num % prime == 0)
        num /= prime;

    return num == 1;
  }
};
