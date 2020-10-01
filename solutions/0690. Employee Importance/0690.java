class Solution {
  public int getImportance(List<Employee> employees, int id) {
    Map<Integer, Employee> idToEmployee = new HashMap<>();

    for (Employee employee : employees)
      idToEmployee.put(employee.id, employee);

    return dfs(idToEmployee, id);
  }

  private int dfs(Map<Integer, Employee> idToEmployee, int id) {
    int subordinatesImportance = 0;

    for (int subordinate : idToEmployee.get(id).subordinates)
      subordinatesImportance += dfs(idToEmployee, subordinate);

    return idToEmployee.get(id).importance + subordinatesImportance;
  }
}