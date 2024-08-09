class Solution {
 public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    long maxPower = 1;
    long hash = 0;
    int bestLeft = -1;

    auto val = [](char c) -> int { return c - 'a' + 1; };

    for (int i = s.length() - 1; i >= 0; --i) {
      hash = (hash * power + val(s[i])) % modulo;
      if (i + k < s.length())
        hash = (hash - val(s[i + k]) * maxPower % modulo + modulo) % modulo;
      else
        maxPower = maxPower * power % modulo;
      if (hash == hashValue)
        bestLeft = i;
    }

    return s.substr(bestLeft, k);
  }
};
