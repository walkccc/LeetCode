SELECT
  Manager.employee_id,
  Manager.name,
  COUNT(Employee.employee_id) AS reports_count,
  ROUND(AVG(Employee.age)) AS average_age
FROM Employees AS Manager
INNER JOIN Employees AS Employee
  ON (Employee.reports_to = Manager.employee_id)
GROUP BY 1
ORDER BY 1;
