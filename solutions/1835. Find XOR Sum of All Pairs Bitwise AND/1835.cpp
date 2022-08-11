class Solution {
 public:
  int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    const int xors1 = accumulate(begin(arr1), end(arr1), 0, bit_xor<>());
    const int xors2 = accumulate(begin(arr2), end(arr2), 0, bit_xor<>());
    return xors1 & xors2;
  }
};
