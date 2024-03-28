class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int ans = 0;
    int depth = 0;
    queue<NestedInteger> q;

    addIntegers(q, nestedList);

    while (!q.empty()) {
      ++depth;
      for (int sz = q.size(); sz > 0; --sz) {
        const NestedInteger ni = q.front();
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
    for (const NestedInteger& ni : nestedList)
      q.push(ni);
  }
};
