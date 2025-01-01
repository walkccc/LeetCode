class Solution {
 public:
  int minPartitions(string n) {
    return ranges::max(n) - '0';
  }
};
