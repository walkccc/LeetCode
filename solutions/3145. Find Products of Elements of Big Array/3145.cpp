class Solution {
 public:
  vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
    vector<int> ans;

    for (const vector<long long>& query : queries) {
      const long a = query[0];
      const long b = query[1];
      const int mod = query[2];
      const int product = modPow(2,
                                 sumPowersFirstKBigNums(b + 1) -  //
                                     sumPowersFirstKBigNums(a),
                                 mod);
      ans.push_back(product);
    }

    return ans;
  }

 private:
  // Returns the sum of powers of the first k numbers in `big_nums`.
  long sumPowersFirstKBigNums(long k) {
    const long num = firstNumberHavingSumBitsTillGreaterThan(k);
    long sumPowers = sumPowersTill(num - 1);
    long remainingCount = k - sumBitsTill(num - 1);
    for (int power = 0; power < bitLength(num); ++power) {
      if (num >> power & 1) {
        sumPowers += power;
        --remainingCount;
        if (remainingCount == 0)
          break;
      }
    }
    return sumPowers;
  }

  // Returns the first number in [1, k] that has sumBitsTill(num) >= k.
  long firstNumberHavingSumBitsTillGreaterThan(long k) {
    long l = 1;
    long r = k;
    while (l < r) {
      const long m = (l + r) / 2;
      if (sumBitsTill(m) < k)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  // Returns sum(i.bit_count()), where 1 <= i <= x.
  long sumBitsTill(long x) {
    long sumBits = 0;
    for (long powerOfTwo = 1; powerOfTwo <= x; powerOfTwo *= 2) {
      sumBits += (x / (2L * powerOfTwo)) * powerOfTwo;
      sumBits += max(0L, x % (2L * powerOfTwo) + 1 - powerOfTwo);
    }
    return sumBits;
  }

  // Returns sum(all powers of i), where 1 <= i <= x.
  long sumPowersTill(long x) {
    long sumPowers = 0;
    long powerOfTwo = 1;
    for (int power = 0; power < bitLength(x); ++power) {
      sumPowers += (x / (2L * powerOfTwo)) * powerOfTwo * power;
      sumPowers += max(0L, x % (2L * powerOfTwo) + 1 - powerOfTwo) * power;
      powerOfTwo *= 2;
    }
    return sumPowers;
  }

  int modPow(long x, long n, int mod) {
    if (n == 0)
      return 1 % mod;
    if (n % 2 == 1)
      return x * modPow(x % mod, (n - 1), mod) % mod;
    return modPow(x * x % mod, (n / 2), mod) % mod;
  }

  int bitLength(long x) {
    return x == 0 ? 0 : 64 - __builtin_clzl(x);
  }
};
