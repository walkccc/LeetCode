class Solution {
 public:
  int countOdds(int low, int high) {
    return (high + 1) / 2 - low / 2;
  }
};
