class Solution {
 public:
  bool isStrobogrammatic(string num) {
    vector<char> rotated{'0', '1', 'x', 'x', 'x', 'x', '9', 'x', '8', '6'};

    for (int l = 0, r = num.length() - 1; l <= r; ++l, --r)
      if (rotated[num[l] - '0'] != num[r])
        return false;

    return true;
  }
};
