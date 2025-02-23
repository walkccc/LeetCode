SELECT
  emp_id,
  firstname,
  lastname,
  MAX(salary) AS salary,
  department_id
FROM Salary
GROUP BY 1
ORDER BY 1;
