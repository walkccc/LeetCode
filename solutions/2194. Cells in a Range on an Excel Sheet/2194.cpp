class Solution {
 public:
  vector<string> cellsInRange(string s) {
    vector<string> ans;
    const char startCol = s[0];
    const char endCol = s[3];
    const char startRow = s[1];
    const char endRow = s[4];

    for (char col = startCol; col <= endCol; ++col)
      for (char row = startRow; row <= endRow; ++row)
        ans.push_back(string(1, col) + row);

    return ans;
  }
};
