class Solution {
 public:
  Node* construct(vector<vector<int>>& grid) {
    function<Node*(int, int, int)> helper = [&](int i, int j, int w) -> Node* {
      if (all_of(begin(grid) + i, begin(grid) + i + w, [&](vector<int>& row) {
            return all_of(begin(row) + j, begin(row) + j + w,
                          [&](int num) { return num == grid[i][j]; });
          }))
        return new Node(grid[i][j], true);

      Node* node = new Node(true, false);
      node->topLeft = helper(i, j, w / 2);
      node->topRight = helper(i, j + w / 2, w / 2);
      node->bottomLeft = helper(i + w / 2, j, w / 2);
      node->bottomRight = helper(i + w / 2, j + w / 2, w / 2);
      return node;
    };

    return helper(0, 0, grid.size());
  }
};