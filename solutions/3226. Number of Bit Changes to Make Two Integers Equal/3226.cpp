class Solution {
 public:
  int minChanges(unsigned n, unsigned k) {
    // n needs to be a superset of k.
    return (n & k) == k ? popcount(n ^ k) : -1;
  }
};
