class Solution {
 public:
  string abbreviateProduct(int left, int right) {
    constexpr long long maxSuf = 1000000000000;
    double prod = 1.0;
    long long suf = 1;
    int countDigits = 0;
    int countZeros = 0;

    for (int num = left; num <= right; ++num) {
      prod *= num;
      while (prod >= 1.0) {
        prod /= 10;
        ++countDigits;
      }
      suf *= num;
      while (suf % 10 == 0) {
        suf /= 10;
        ++countZeros;
      }
      if (suf > maxSuf)
        suf %= maxSuf;
    }

    if (countDigits - countZeros <= 10) {
      const long tens = pow(10, countDigits - countZeros);
      return to_string(static_cast<long>(prod * tens + 0.5)) + 'e' +
             to_string(countZeros);
    }

    const string pre = to_string((long)(prod * pow(10, 5)));
    string sufStr = to_string(suf);
    sufStr = sufStr.substr(sufStr.length() - 5);
    return pre + "..." + sufStr + 'e' + to_string(countZeros);
  }
};
