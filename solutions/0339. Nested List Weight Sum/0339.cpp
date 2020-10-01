class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int ans = 0;
    int depth = 1;
    queue<NestedInteger> q;

    auto addInteger = [&](const vector<NestedInteger>& nestedList) {
      for (const NestedInteger& ni : nestedList)
        if (ni.isInteger())
          ans += ni.getInteger() * depth;
        else
          q.push(ni);
    };

    addInteger(nestedList);

    while (!q.empty()) {
      ++depth;
      for (int i = q.size(); i > 0; --i) {
        const auto ni = q.front(); q.pop();
        addInteger(ni.getList());
      }
    }

    return ans;
  }
};