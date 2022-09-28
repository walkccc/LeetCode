class Solution {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    multiset<int> set{begin(A), end(A)};

    for (int i = 0; i < B.size(); ++i) {
      auto p = *rbegin(set) <= B[i] ? begin(set) : set.upper_bound(B[i]);
      A[i] = *p;
      set.erase(p);
    }

    return A;
  }
};
