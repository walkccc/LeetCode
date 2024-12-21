class Solution {
 public:
  bool checkZeroOnes(string s) {
    int longestOnes = 0;
    int longestZeros = 0;
    int currentOnes = 0;
    int currentZeros = 0;

    for (const char c : s)
      if (c == '0') {
        currentOnes = 0;
        longestZeros = max(longestZeros, ++currentZeros);
      } else {
        currentZeros = 0;
        longestOnes = max(longestOnes, ++currentOnes);
      }

    return longestOnes > longestZeros;
  }
};
