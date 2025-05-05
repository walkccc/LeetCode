class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>> ans{{"Table"}};
    unordered_map<string, int> tableNumberToRowIndex;
    unordered_map<string, int> foodItemToColIndex;

    // Create the first row and column of ans.
    for (const vector<string>& order : orders) {
      const string& tableNumber = order[1];
      const string& foodItem = order[2];
      // Initialize indices with 0s.
      tableNumberToRowIndex[tableNumber] = 0;
      foodItemToColIndex[foodItem] = 0;
    }
    for (const auto& [tableNumber, _] : tableNumberToRowIndex)
      ans.push_back({tableNumber});
    for (const auto& [foodItem, _] : foodItemToColIndex)
      ans[0].push_back(foodItem);

    // Sort the first row and the column, except ans[0][0].
    sort(ans[0].begin() + 1, ans[0].end());
    ranges::sort(ans.begin() + 1, ans.end(), ranges::less{},
                 [](const vector<string>& cols) { return stoi(cols[0]); });

    // Set the indices after sorting.
    for (int i = 0; i < tableNumberToRowIndex.size(); ++i)
      tableNumberToRowIndex[ans[i + 1][0]] = i;
    for (int i = 0; i < foodItemToColIndex.size(); ++i)
      foodItemToColIndex[ans[0][i + 1]] = i;

    // Get all the counts of each food item in each table.
    vector<vector<int>> count;
    for (int i = 0; i < tableNumberToRowIndex.size(); ++i)
      count.push_back(vector<int>(foodItemToColIndex.size()));
    for (const vector<string>& order : orders) {
      const string& tableNumber = order[1];
      const string& foodItem = order[2];
      const int rowIndex = tableNumberToRowIndex[tableNumber];
      const int colIndex = foodItemToColIndex[foodItem];
      ++count[rowIndex][colIndex];
    }

    // Set the counts to `ans`.
    for (int i = 0; i < tableNumberToRowIndex.size(); ++i)
      for (int j = 0; j < foodItemToColIndex.size(); ++j)
        ans[i + 1].push_back(to_string(count[i][j]));

    return ans;
  }
};
