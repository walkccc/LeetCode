class Solution {
 public:
  bool squareIsWhite(string coordinates) {
    const char letter = coordinates[0];
    const char digit = coordinates[1];
    return letter % 2 != digit % 2;
  }
};
