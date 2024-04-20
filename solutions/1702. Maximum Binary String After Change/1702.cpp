class Solution {
 public:
  string maximumBinaryString(string binary) {
    //     e.g. binary = "100110"
    // Do Operation 2 -> "100011"
    // Do Operation 1 -> "111011"
    // So, the index of the only '0' is prefixOnes + zeros - 1.
    const int zeros = ranges::count(binary, '0');
    const int prefixOnes = binary.find('0');

    // Make the entire string as 1s.
    binary.assign(binary.length(), '1');

    // Make the only '0' if necessary.
    if (prefixOnes != string::npos)
      binary[prefixOnes + zeros - 1] = '0';
    return binary;
  }
};
