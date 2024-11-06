class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y)
      return y - x;

    queue<int> q{{x}};
    unordered_set<int> seen;

    for (int ans = 0; !q.empty(); ++ans) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int num = q.front();
        q.pop();
        if (num == y)
          return ans;
        if (seen.find(num) != seen.end())
          continue;
        seen.insert(num);
        if (num % 11 == 0)
          q.push(num / 11);
        if (num % 5 == 0)
          q.push(num / 5);
        q.push(num - 1);
        q.push(num + 1);
      }
    }

    throw;
  }
};
