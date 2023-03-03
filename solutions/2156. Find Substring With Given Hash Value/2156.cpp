class Solution {
 public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    long maxPower = 1;
    long hashed = 0;
    int bestLeft = -1;

    auto val = [](char c) -> int { return c - 'a' + 1; };

    for (int i = s.length() - 1; i >= 0; --i) {
      hashed = (hashed * power + val(s[i])) % modulo;
      if (i + k < s.length())
        hashed = (hashed - val(s[i + k]) * maxPower % modulo + modulo) % modulo;
      else
        maxPower = maxPower * power % modulo;
      if (hashed == hashValue)
        bestLeft = i;
    }

    return s.substr(bestLeft, k);
  }
};
