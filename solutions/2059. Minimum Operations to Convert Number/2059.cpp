class Solution {
 public:
  int minimumOperations(vector<int>& nums, int start, int goal) {
    int ans = 0;
    queue<int> q{{start}};
    vector<bool> seen(1001);
    seen[start] = true;

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const int x = q.front();
        q.pop();
        for (const int num : nums) {
          for (const int res : {x + num, x - num, x ^ num}) {
            if (res == goal)
              return ans;
            if (res < 0 || res > 1000 || seen[res])
              continue;
            seen[res] = true;
            q.push(res);
          }
        }
      }
    }

    return -1;
  }
};
