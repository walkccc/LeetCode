class Solution {
 public:
  int countNumbers(const string& l, const string& r, const int b) {
    const vector<int> rDigits = convertToBaseB(r, b);
    vector<int> lDigits = convertToBaseB(l, b);
    vector<int> lMinus1Digits = convertToBaseB(decrement(l), b);
    padToSameLength(lDigits, rDigits);
    padToSameLength(lMinus1Digits, rDigits);
    return (countWithMem(rDigits, b) - countWithMem(lMinus1Digits, b) + kMod) %
           kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  void padToSameLength(vector<int>& a, const vector<int>& b) {
    a.insert(a.begin(), b.size() - a.size(), 0);
  }

  int countWithMem(const vector<int>& digits, const int b) {
    vector<vector<vector<int>>> mem(digits.size(),
                                    vector<vector<int>>(2, vector<int>(b, -1)));
    return count(digits, 0, 0, true, b, mem);
  }

  int count(const vector<int>& num, int pos, int lastDigit, bool tight, int b,
            vector<vector<vector<int>>>& mem) {
    if (pos == num.size())
      return 1;

    if (mem[pos][tight][lastDigit] != -1)
      return mem[pos][tight][lastDigit];

    int res = 0;
    const int limit = tight ? num[pos] : b - 1;

    for (int d = lastDigit; d <= limit; d++) {
      const bool newTight = tight && (d == limit);
      res = (res + count(num, pos + 1, d, newTight, b, mem)) % kMod;
    }

    return mem[pos][tight][lastDigit] = res;
  }

  string decrement(string s) {
    for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] > '0') {
        --s[i];
        break;
      } else {
        s[i] = '9';
      }
    }
    return s[0] == '0' && s.length() > 1 ? s.substr(1) : s;
  }

  vector<int> convertToBaseB(const string& numStr, const int b) {
    vector<int> digits;
    vector<int> currentNum(1, 0);

    for (const char c : numStr) {
      const int d = c - '0';

      int carry = 0;
      for (int i = 0; i < currentNum.size(); ++i) {
        const long long product = (long long)currentNum[i] * 10 + carry;
        currentNum[i] = product % b;
        carry = product / b;
      }

      while (carry > 0) {
        currentNum.push_back(carry % b);
        carry /= b;
      }

      carry = d;
      for (int i = 0; i < currentNum.size() && carry; ++i) {
        const int sum = currentNum[i] + carry;
        currentNum[i] = sum % b;
        carry = sum / b;
      }

      while (carry > 0) {
        currentNum.push_back(carry % b);
        carry /= b;
      }
    }

    for (int i = currentNum.size() - 1; i >= 0; --i)
      digits.push_back(currentNum[i]);

    if (digits.empty())
      digits.push_back(0);

    return digits;
  }
};
