class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    //      original = [O[0], O[1], ..., O[n - 1]]
    //       derived = [O[0]^O[1], O[1]^O[2], ..., O[n - 1]^O[0]]
    // XOR(derivedd) = 0
    return accumulate(derived.begin(), derived.end(), 0, bit_xor<>()) == 0;
  }
};
