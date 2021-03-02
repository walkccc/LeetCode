class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> count;
    int gcd = 0;

    for (int d : deck)
      ++count[d];

    for (const auto& [_, value] : count)
      gcd = __gcd(gcd, value);

    return gcd >= 2;
  }
};
