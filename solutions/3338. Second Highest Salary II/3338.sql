WITH
  RankedEmployees AS (
    SELECT *, DENSE_RANK() OVER(
      PARTITION BY dept
      ORDER BY salary DESC
    ) AS `rank`
    FROM Employees
  )
SELECT emp_id, dept
FROM RankedEmployees
WHERE `rank` = 2
ORDER BY 1;
