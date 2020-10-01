class Solution {
 public:
  bool isStrobogrammatic(string num) {
    vector<char> rotated{'0', '1', 'n', 'n', 'n', 'n', '9', 'n', '8', '6'};

    for (int i = 0; i < num.length(); ++i)
      if (rotated[num[i] - '0'] != num[num.length() - 1 - i])
        return false;

    return true;
  }
};