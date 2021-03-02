class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int sum = accumulate(begin(A), end(A), 0);
    int prefix = 0;
    int parts = 1;

    for (int a : A) {
      prefix += a;
      if (prefix == sum * parts / 3)
        ++parts;
    }

    return sum % 3 == 0 && parts >= 3;
  }
};
