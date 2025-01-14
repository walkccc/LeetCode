class Solution {
 public:
  long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                               long long k) {
    vector<int> A1;
    vector<int> A2;
    vector<int> B1;
    vector<int> B2;

    seperate(nums1, A1, A2);
    seperate(nums2, B1, B2);

    const long negCount = A1.size() * B2.size() + A2.size() * B1.size();
    int sign = 1;

    if (k > negCount) {
      k -= negCount;  //  Find (k - negCount)-th positive.
    } else {
      k = negCount - k + 1;  // Find (negCount - k + 1)-th abs(negative).
      sign = -1;
      swap(B1, B2);
    }

    long l = 0;
    long r = 1e10;

    while (l < r) {
      const long m = (l + r) / 2;
      if (numProductNoGreaterThan(A1, B1, m) +
              numProductNoGreaterThan(A2, B2, m) >=
          k)
        r = m;
      else
        l = m + 1;
    }

    return sign * l;
  }

 private:
  void seperate(const vector<int>& A, vector<int>& A1, vector<int>& A2) {
    for (const int a : A)
      if (a < 0)
        A1.push_back(-a);
      else
        A2.push_back(a);
    ranges::reverse(A1);  // Reverse to sort ascending
  }

  long numProductNoGreaterThan(const vector<int>& A, const vector<int>& B,
                               long m) {
    long count = 0;
    int j = B.size() - 1;
    // For each a, find the first index j s.t. a * B[j] <= m
    // So numProductNoGreaterThan m for this row will be j + 1
    for (const long a : A) {
      while (j >= 0 && a * B[j] > m)
        --j;
      count += j + 1;
    }
    return count;
  }
};
