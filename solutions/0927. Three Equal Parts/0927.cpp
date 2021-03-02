class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& A) {
    int ones = count_if(begin(A), end(A), [](int a) { return a == 1; });

    if (ones == 0)
      return {0, A.size() - 1};
    if (ones % 3 != 0)
      return {-1, -1};

    int k = ones / 3;
    int i;
    int j;
    int first;
    int second;
    int third;

    for (i = 0; i < A.size(); ++i)
      if (A[i] == 1) {
        first = i;
        break;
      }

    int gapOnes = k;

    for (j = i + 1; j < A.size(); ++j)
      if (A[j] == 1 && --gapOnes == 0) {
        second = j;
        break;
      }

    gapOnes = k;

    for (i = j + 1; i < A.size(); ++i)
      if (A[i] == 1 && --gapOnes == 0) {
        third = i;
        break;
      }

    while (third < A.size() && A[first] == A[second] && A[second] == A[third]) {
      ++first;
      ++second;
      ++third;
    }

    if (third == A.size())
      return {first - 1, second};
    return {-1, -1};
  }
};
