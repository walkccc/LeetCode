class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& arr) {
    const int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0)
      return false;

    const int average = sum / 3;
    int partCount = 0;
    int partSum = 0;

    for (const int a : arr) {
      partSum += a;
      if (partSum == average) {
        ++partCount;
        partSum = 0;
      }
    }

    // edge case: arr = [0, 0, 0, 0] -> partCount = 4.
    return partCount >= 3;
  }
};
