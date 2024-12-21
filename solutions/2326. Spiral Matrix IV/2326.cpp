class Solution {
 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> ans(m, vector<int>(n, -1));
    int x = 0;  // the current x position
    int y = 0;  // the current y position
    int d = 0;

    for (ListNode* curr = head; curr; curr = curr->next) {
      ans[x][y] = curr->val;
      if (x + dirs[d][0] < 0 || x + dirs[d][0] == m || y + dirs[d][1] < 0 ||
          y + dirs[d][1] == n || ans[x + dirs[d][0]][y + dirs[d][1]] != -1)
        d = (d + 1) % 4;
      x += dirs[d][0];
      y += dirs[d][1];
    }

    return ans;
  }
};
