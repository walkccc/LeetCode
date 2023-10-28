WITH
  EmployeesWithRankInCompany AS (
    SELECT
      id,
      company,
      salary,
      ROW_NUMBER() OVER(
        PARTITION BY company
        ORDER BY salary
      ) AS `rank`,
      COUNT(*) OVER(PARTITION BY company) AS `count`
    FROM Employee
  )
SELECT id, company, salary
FROM EmployeesWithRankInCompany
WHERE `rank` >= `count` / 2
  AND `rank` <= `count` / 2 + 1;
