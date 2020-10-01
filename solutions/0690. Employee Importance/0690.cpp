class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> idToEmployee;

    for (Employee* employee : employees)
      idToEmployee[employee->id] = employee;

    function<int(int)> dfs = [&](int id) {
      int subordinatesImportance = idToEmployee[id]->importance;

      for (const int subordinate : idToEmployee[id]->subordinates)
        subordinatesImportance += dfs(subordinate);

      return subordinatesImportance;
    };

    return dfs(id);
  }
};