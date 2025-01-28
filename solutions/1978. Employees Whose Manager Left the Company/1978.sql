SELECT Employee.employee_id
FROM Employees AS Employee
LEFT JOIN Employees AS Manager
  ON (Employee.manager_id = Manager.employee_id)
WHERE
  Employee.salary < 30000
  AND Employee.manager_id IS NOT NULL
  AND Manager.employee_id IS NULL
ORDER BY 1;
