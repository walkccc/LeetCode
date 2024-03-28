class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int currShift = 0;
    vector<int> timeline(s.length() + 1);

    for (const vector<int>& shift : shifts) {
      const int start = shift[0];
      const int end = shift[1];
      const int direction = shift[2];
      const int diff = direction ? 1 : -1;
      timeline[start] += diff;
      timeline[end + 1] -= diff;
    }

    for (int i = 0; i < s.length(); ++i) {
      currShift = (currShift + timeline[i]) % 26;
      const int num = (s[i] - 'a' + currShift + 26) % 26;
      s[i] = 'a' + num;
    }

    return s;
  }
};
