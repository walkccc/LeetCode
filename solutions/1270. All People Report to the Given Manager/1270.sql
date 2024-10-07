SELECT Employee.employee_id
FROM Employees AS Employee
INNER JOIN Employees AS DirectManager
  ON (Employee.manager_id = DirectManager.employee_id)
INNER JOIN Employees AS SkipManager
  ON (DirectManager.manager_id = SkipManager.employee_id)
WHERE
  SkipManager.manager_id = 1
  AND Employee.employee_id != 1;
