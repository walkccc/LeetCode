class Solution {
 public:
  bool checkTwoChessboards(string coordinate1, string coordinate2) {
    return squareIsWhite(coordinate1) == squareIsWhite(coordinate2);
  }

 private:
  // Same as 1812. Determine Color of a Chessboard Square
  bool squareIsWhite(const string& coordinates) {
    const char letter = coordinates[0];
    const char digit = coordinates[1];
    return letter % 2 != digit % 2;
  }
};
