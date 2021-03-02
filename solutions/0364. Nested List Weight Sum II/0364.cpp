class Solution {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int ans = 0;
    int prevSum = 0;
    queue<NestedInteger> q{{begin(nestedList), end(nestedList)}};

    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        const NestedInteger ni = q.front();
        q.pop();
        if (ni.isInteger())
          prevSum += ni.getInteger();
        else {
          for (const NestedInteger nextNi : ni.getList())
            q.push(nextNi);
        }
      }
      ans += prevSum;
    }

    return ans;
  }
};
