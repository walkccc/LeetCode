class Solution {
 public:
  char kthCharacter(unsigned k) {
    return 'a' + popcount(k - 1);
  }
};
