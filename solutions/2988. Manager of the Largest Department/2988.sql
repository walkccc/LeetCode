WITH
  RankedDepartments AS (
    SELECT
      dep_id,
      DENSE_RANK() OVER(
        ORDER BY COUNT(*) DESC
      ) AS `rank`
    FROM Employees
    GROUP BY 1
  )
SELECT
  Employees.emp_name AS manager_name,
  Employees.dep_id
FROM Employees
INNER JOIN RankedDepartments
  USING (dep_id)
WHERE
  Employees.position = 'Manager'
  AND RankedDepartments.`rank` = 1
ORDER BY dep_id;
