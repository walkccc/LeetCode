class SQL {
 public:
  void insertRow(string name, vector<string> row) {
    db[name].push_back(row);
  }

  void deleteRow(string name, int rowId) {}

  string selectCell(string name, int rowId, int columnId) {
    return db[name][rowId - 1][columnId - 1];
  }

 private:
  unordered_map<string, vector<vector<string>>> db;
};
