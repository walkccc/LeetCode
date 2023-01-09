class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> idToEmployee;

    for (Employee* employee : employees)
      idToEmployee[employee->id] = employee;

    return dfs(id, idToEmployee);
  }

 private:
  int dfs(int id, const unordered_map<int, Employee*>& idToEmployee) {
    int values = 0;

    for (const int subId : idToEmployee.at(id)->subordinates)
      values += dfs(subId, idToEmployee);

    return idToEmployee.at(id)->importance + values;
  }
};
