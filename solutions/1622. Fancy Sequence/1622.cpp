class Fancy {
 public:
  // To undo a * val + b and get the original value, we append (val - b) / a.
  // By Fermat's little theorem:
  //   a^(p - 1) ≡ 1 (mod p)
  //   a^(p - 2) ≡ a^(-1) (mod p)
  // So, (val - b) / a ≡ (val - b) * a^(p - 2) (mod p)
  void append(int val) {
    const long x = (val - b + kMod) % kMod;
    vals.push_back(x * modPow(a, kMod - 2) % kMod);
  }

  // If the value is a * val + b, then the value after adding by `inc` will be
  // a * val + b + inc. So, we adjust b to b + inc.
  void addAll(int inc) {
    b = (b + inc) % kMod;
  }

  // If the value is a * val + b, then the value after multiplying by `m` will
  // be a * m * val + b * m. So, we adjust a to a * m and b to b * m.
  void multAll(int m) {
    a = (a * m) % kMod;
    b = (b * m) % kMod;
  }

  int getIndex(int idx) {
    return idx >= vals.size() ? -1 : (a * vals[idx] + b) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  // For each `val` in `vals`, it actually represents a * val + b.
  vector<unsigned long> vals;
  unsigned long a = 1;
  unsigned long b = 0;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
