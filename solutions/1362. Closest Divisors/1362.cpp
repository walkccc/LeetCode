class Solution {
 public:
  vector<int> closestDivisors(int num) {
    for (int root = sqrt(num + 2); root > 0; --root)
      for (int cand : {num + 1, num + 2})
        if (cand % root == 0)
          return {root, cand / root};

    throw;
  }
};
