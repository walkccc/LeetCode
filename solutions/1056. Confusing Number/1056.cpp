class Solution {
 public:
  bool confusingNumber(int n) {
    const string s = to_string(n);
    const vector<char> rotated{'0', '1', 'x', 'x', 'x',
                               'x', '9', 'x', '8', '6'};
    string rotatedNum;

    for (int i = s.length() - 1; i >= 0; --i) {
      if (rotated[s[i] - '0'] == 'x')
        return false;
      rotatedNum += rotated[s[i] - '0'];
    }

    return rotatedNum != s;
  }
};
