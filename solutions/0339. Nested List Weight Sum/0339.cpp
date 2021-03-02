class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int ans = 0;
    int depth = 0;
    queue<NestedInteger> q;

    addIntegers(q, nestedList);

    while (!q.empty()) {
      ++depth;
      for (int size = q.size(); size > 0; --size) {
        const auto ni = q.front();
        q.pop();
        if (ni.isInteger())
          ans += ni.getInteger() * depth;
        else
          addIntegers(q, ni.getList());
      }
    }

    return ans;
  }

 private:
  void addIntegers(queue<NestedInteger>& q,
                   const vector<NestedInteger>& nestedList) {
    for (const auto& ni : nestedList)
      q.push(ni);
  }
};
