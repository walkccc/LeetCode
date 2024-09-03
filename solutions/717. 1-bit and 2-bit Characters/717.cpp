class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    const int n = bits.size();

    int i = 0;
    while (i < n - 1)
      if (bits[i] == 0)
        i += 1;
      else
        i += 2;

    return i == n - 1;
  }
};
