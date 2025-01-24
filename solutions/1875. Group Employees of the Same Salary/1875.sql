WITH
  EmployeesWithCountPerSalary AS (
    SELECT
      *,
      COUNT(employee_id) OVER(PARTITION BY salary) AS count_per_salary
    FROM Employees
  )
SELECT
  employee_id,
  name,
  salary,
  DENSE_RANK() OVER(ORDER BY salary) AS team_id
FROM EmployeesWithCountPerSalary
WHERE count_per_salary > 1
ORDER BY team_id, employee_id;
