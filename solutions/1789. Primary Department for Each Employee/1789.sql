SELECT
  employee_id,
  department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION DISTINCT
SELECT
  employee_id,
  department_id
FROM Employee
GROUP BY 1
HAVING COUNT(*) = 1;
