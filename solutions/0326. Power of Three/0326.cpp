class Solution {
 public:
  bool isPowerOfThree(int n) {
    return n > 0 && static_cast<int>(pow(3, 19)) % n == 0;
  }
};
