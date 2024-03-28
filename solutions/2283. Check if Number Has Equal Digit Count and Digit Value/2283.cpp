class Solution {
 public:
  bool digitCount(string num) {
    vector<int> count(10);

    for (const char c : num)
      ++count[c - '0'];

    for (int i = 0; i < num.length(); ++i)
      if (count[i] != num[i] - '0')
        return false;

    return true;
  }
};
