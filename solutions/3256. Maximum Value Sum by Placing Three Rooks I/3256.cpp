class Solution {
 public:
  long long maximumValueSum(vector<vector<int>>& board) {
    const int m = board.size();
    const int n = board[0].size();
    long ans = LONG_MIN;
    using T = tuple<long, int, int>;
    vector<vector<T>> rows(m);  // [(val, i, j)]
    vector<vector<T>> cols(n);  // [(val, i, j)]
    set<T> rowSet;              // {(val, i, j)}
    set<T> colSet;              // {(val, i, j)}
    set<T> topNine;             // {(val, i, j)}

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        rows[i].emplace_back(board[i][j], i, j);
        cols[j].emplace_back(board[i][j], i, j);
      }

    auto getTop3 = [](vector<T>& row) -> vector<T> {
      partial_sort(row.begin(),
                   row.begin() + min(3, static_cast<int>(row.size())),
                   row.end(), greater<>());
      row.resize(min(3, (int)row.size()));
      return row;
    };

    for (vector<T>& row : rows) {
      row = getTop3(row);
      rowSet.insert(row.begin(), row.end());
    }

    for (vector<T>& col : cols) {
      col = getTop3(col);
      colSet.insert(col.begin(), col.end());
    }

    set_intersection(rowSet.begin(), rowSet.end(), colSet.begin(), colSet.end(),
                     inserter(topNine, topNine.begin()));

    // At least 9 positions are required on the board to place 3 rooks such that
    // none can attack another.
    if (topNine.size() > 9) {
      auto it = topNine.begin();
      advance(it, topNine.size() - 9);
      topNine.erase(topNine.begin(), it);
    }

    for (auto it1 = topNine.begin(); it1 != topNine.end(); ++it1)
      for (auto it2 = next(it1); it2 != topNine.end(); ++it2)
        for (auto it3 = next(it2); it3 != topNine.end(); ++it3) {
          const auto [val1, i1, j1] = *it1;
          const auto [val2, i2, j2] = *it2;
          const auto [val3, i3, j3] = *it3;
          if (i1 == i2 || i1 == i3 || i2 == i3 ||  //
              j1 == j2 || j1 == j3 || j2 == j3)
            continue;
          ans = max(ans, val1 + val2 + val3);
        }

    return ans;
  }
};
