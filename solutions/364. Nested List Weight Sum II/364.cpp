class Solution {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int ans = 0;
    int prevSum = 0;
    queue<NestedInteger> q{{nestedList.begin(), nestedList.end()}};

    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
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
