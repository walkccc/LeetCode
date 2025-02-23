WITH
  EmployeesWithRowNumberInCompany AS (
    SELECT
      id,
      company,
      salary,
      ROW_NUMBER() OVER(
        PARTITION BY company
        ORDER BY salary
      ) AS `row_number`,
      COUNT(*) OVER(PARTITION BY company) AS `count`
    FROM Employee
  )
SELECT id, company, salary
FROM EmployeesWithRowNumberInCompany
WHERE
  `row_number` >= `count` / 2
  AND `row_number` <= `count` / 2 + 1;
