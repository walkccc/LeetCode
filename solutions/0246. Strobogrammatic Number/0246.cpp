class Solution {
 public:
  bool isStrobogrammatic(string num) {
    const vector<char> rotated{'0', '1', 'x', 'x', 'x',
                               'x', '9', 'x', '8', '6'};
    int l = 0;
    int r = num.length() - 1;

    while (l <= r)
      if (num[l++] != rotated[num[r--] - '0'])
        return false;

    return true;
  }
};
