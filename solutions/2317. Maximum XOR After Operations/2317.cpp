class Solution {
 public:
  int maximumXOR(vector<int>& nums) {
    // 1. nums[i] & (nums[i] ^ x) enables you to turn 1-bit to 0-bit from
    //    nums[i] since x is arbitrary.
    // 2. The i-th bit of the XOR of all the elements is 1 if the i-th bit is 1
    //    for an odd number of elements.
    // 3. Therefore, the question is equivalent to: if you can convert any digit
    //    from 1 to 0 for any number, what is the max for XOR(nums[i]).
    // 4. The max we can get is of course to make every digit of the answer to
    //    be 1 if possible
    // 5. Therefore, OR(nums[i]) is an approach.
    return reduce(begin(nums), end(nums), 0, bit_or());
  }
};
