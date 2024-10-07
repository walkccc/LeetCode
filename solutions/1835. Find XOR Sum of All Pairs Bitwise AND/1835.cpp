class Solution {
 public:
  int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    const int xors1 = accumulate(arr1.begin(), arr1.end(), 0, bit_xor<>());
    const int xors2 = accumulate(arr2.begin(), arr2.end(), 0, bit_xor<>());
    return xors1 & xors2;
  }
};
