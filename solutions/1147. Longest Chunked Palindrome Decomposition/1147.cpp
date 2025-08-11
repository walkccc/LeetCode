class Solution {
 public:
  int longestDecomposition(string text) {
    int count = 0;
    int l = 0;

    for (int r = 1; 2 * r <= text.length(); ++r)
      if (equal(text.begin() + l, text.begin() + r, text.end() - r)) {
        count += 2;
        l = r;
      }

    return count + (2 * l < text.length());
  }
};
