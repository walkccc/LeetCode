class Solution {
 public:
  vector<int> decode(vector<int>& encoded) {
    // Our goal is to find the value of a1, which will allow us to decode a2,
    // a3, ..., an. This can be achieved by performing XOR operation between
    // each element in `encoded` and a1.
    //
    // e.g. n = 3, perm = [a1, a2, a3] is a permutation of [1, 2, 3]
    //               encoded = [a1^a2, a2^a3]
    //    accumulatedEncoded = [a1^a2, a1^a3]
    //    a1 = (a1^a2)^(a1^a3)^(a1^a2^a3)
    //    a2 = a1^(a1^a2)
    //    a3 = a2^(a2^a3)
    const int n = encoded.size() + 1;
    int nXors = 0;
    for (int i = 1; i <= n; i++)
      nXors ^= i;

    // Instead of constructing the array, we can track of the running XOR value
    // of `accumulatedEncoded`.
    int runningXors = 0;
    int xors = 0;  // xors(accumulatedEncoded)

    for (const int encode : encoded) {
      runningXors ^= encode;
      xors ^= runningXors;
    }

    vector<int> ans{xors ^ nXors};

    for (const int encode : encoded)
      ans.push_back(ans.back() ^ encode);

    return ans;
  }
};
