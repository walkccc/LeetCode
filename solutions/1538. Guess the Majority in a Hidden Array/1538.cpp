/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *  public:
 *   // Compares 4 different elements in the array
 *   // Returns 4 if the values of the 4 elements are the same (0 or 1).
 *   // Returns 2 if three elements have a value equal to 0 and one element has
 *   //           value equal to 1 or vice versa.
 *   // Returns 0 if two element have a value equal to 0 and two elements have
 *   //           a value equal to 1.
 *   int query(int a, int b, int c, int d);
 *
 *   // Returns the length of the array
 *   int length();
 * };
 */

class Solution {
 public:
  int guessMajority(ArrayReader& reader) {
    const int n = reader.length();
    const int query0123 = reader.query(0, 1, 2, 3);
    const int query1234 = reader.query(1, 2, 3, 4);
    // the number of numbers that are same as `nums[0]`
    int count0 = 1;
    // the number of numbers that are different from `nums[0]`
    int countNot0 = 0;
    // any index i s.t. nums[i] != nums[0]
    int indexNot0 = -1;

    // Find which group nums[1..3] belong to.
    for (int i = 1; i <= 3; ++i) {
      vector<int> abcd = getABCD(i);
      if (reader.query(abcd[0], abcd[1], abcd[2], abcd[3]) == query1234) {
        ++count0;
      } else {
        ++countNot0;
        indexNot0 = i;
      }
    }

    // Find which group nums[4..n) belong to.
    for (int i = 4; i < n; ++i)
      if (reader.query(1, 2, 3, i) == query0123) {
        ++count0;
      } else {
        ++countNot0;
        indexNot0 = i;
      }

    if (count0 == countNot0)
      return -1;
    if (count0 > countNot0)
      return 0;
    return indexNot0;
  }

  // Returns [0..4] except i.
 private:
  vector<int> getABCD(int i) {
    vector<int> abcd{0};
    for (int j = 1; j <= 3; ++j)
      if (j != i)
        abcd.push_back(j);
    abcd.push_back(4);
    return abcd;
  }
};
