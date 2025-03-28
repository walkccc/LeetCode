class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0;
    int r = letters.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (letters[m] > target)
        r = m;
      else
        l = m + 1;
    }

    return letters[l % letters.size()];
  }
};
