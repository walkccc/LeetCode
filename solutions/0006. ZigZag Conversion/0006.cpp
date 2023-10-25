class Solution {
 public:
  string convert(string s, int numRows) {
    string ans;
    vector<vector<char>> rows(numRows);
    int k = 0;
    int direction = (numRows == 1) - 1;

    for (const char c : s) {
      rows[k].push_back(c);
      if (k == 0 || k == numRows - 1)
        direction *= -1;
      k += direction;
    }

    for (const vector<char>& row : rows)
      for (const char c : row)
        ans += c;

    return ans;
  }
};
