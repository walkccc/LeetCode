class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    ranges::sort(arr, ranges::less{}, [](const int a) {
      const int bitCount = bitset<32>(a).count();
      return pair<int, int>{bitCount, a};
    });
    return arr;
  }
};
