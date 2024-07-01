SELECT Employees.employee_id
FROM Employees
LEFT JOIN Salaries
  USING (employee_id)
WHERE Salaries.salary IS NULL
UNION ALL
SELECT Salaries.employee_id
FROM Salaries
LEFT JOIN Employees
  USING (employee_id)
WHERE Employees.name IS NULL
ORDER BY 1;
