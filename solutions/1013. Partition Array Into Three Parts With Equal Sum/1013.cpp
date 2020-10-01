class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int sum = accumulate(begin(A), end(A), 0);
    int prefixSum = 0;
    int parts = 1;

    for (int a : A) {
      prefixSum += a;
      if (prefixSum == sum * parts / 3) ++parts;
    }

    return sum % 3 == 0 && parts >= 3;
  }
};