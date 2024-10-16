class Solution {
 public:
  int minOperations(string s) {
    int cost10;  // the cost to make s "1010"

    for (int i = 0; i < s.length(); ++i)
      if (s[i] - '0' == i % 2)
        ++cost10;

    const int cost01 = s.length() - cost10;  // the cost to make s "0101"
    return min(cost10, cost01);
  }
};
