class Solution {
 public:
  int minimumOperations(vector<int>& nums, int start, int goal) {
    queue<int> q{{start}};
    vector<bool> seen(1001);
    seen[start] = true;

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const int x = q.front();
        q.pop();
        for (const int num : nums) {
          for (const int res : {x + num, x - num, x ^ num}) {
            if (res == goal)
              return step;
            if (res < 0 || res > 1000 || seen[res])
              continue;
            seen[res] = true;
            q.push(res);
          }
        }
      }

    return -1;
  }
};
