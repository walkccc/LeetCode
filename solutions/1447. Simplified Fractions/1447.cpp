class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> ans;
    for (int denominator = 2; denominator <= n; ++denominator)
      for (int numerator = 1; numerator < denominator; ++numerator)
        if (__gcd(denominator, numerator) == 1)
          ans.push_back(to_string(numerator) + "/" + to_string(denominator));
    return ans;
  }
};
