class Solution {
  public int getImportance(List<Employee> employees, int id) {
    Map<Integer, Employee> idToEmployee = new HashMap<>();

    for (Employee employee : employees)
      idToEmployee.put(employee.id, employee);

    return dfs(id, idToEmployee);
  }

  private int dfs(int id, Map<Integer, Employee> idToEmployee) {
    int values = 0;

    for (final int subId : idToEmployee.get(id).subordinates)
      values += dfs(subId, idToEmployee);

    return idToEmployee.get(id).importance + values;
  }
}
