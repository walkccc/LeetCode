class Solution {
 public:
  vector<string> ipToCIDR(string ip, int n) {
    vector<string> ans;
    long num = getNum(ip);

    while (n > 0) {
      const long lowbit = num & -num;
      const long count = lowbit == 0 ? maxLow(n) : firstFit(lowbit, n);
      ans.push_back(getCIDR(num, getPrefix(count)));
      n -= count;
      num += count;
    }

    return ans;
  }

 private:
  long getNum(const string& ip) {
    istringstream iss(ip);
    long num = 0;
    for (string token; getline(iss, token, '.');)
      num = num * 256 + stol(token);
    return num;
  }

  // Returns the maximum i s.t. 2^i < n.
  int maxLow(int n) {
    for (int i = 0; i < 32; ++i)
      if (1 << i + 1 > n)
        return 1 << i;
    throw;
  }

  long firstFit(long lowbit, long n) {
    while (lowbit > n)
      lowbit >>= 1;
    return lowbit;
  }

  string getCIDR(long num, long prefix) {
    const long d = num & 255;
    num >>= 8;
    const long c = num & 255;
    num >>= 8;
    const long b = num & 255;
    num >>= 8;
    const long a = num & 255;
    return to_string(a) + '.' + to_string(b) + '.' + to_string(c) + '.' +
           to_string(d) + '/' + to_string(prefix);
  }

  // e.g. count = 8 = 2^3 -> prefix = 32 - 3 = 29
  //      count = 1 = 2^0 -> prefix = 32 - 0 = 32
  int getPrefix(long count) {
    for (int i = 0; i < 32; ++i)
      if (count == 1 << i)
        return 32 - i;
    throw;
  }
};
