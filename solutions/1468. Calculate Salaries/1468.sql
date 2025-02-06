WITH
  SalariesWithMaxSalary AS (
    SELECT
      *,
      MAX(salary) OVER(PARTITION BY company_id) AS max_salary
    FROM Salaries
  )
SELECT
  company_id,
  employee_id,
  employee_name,
  ROUND(
    CASE
      WHEN max_salary < 1000 THEN salary
      WHEN max_salary BETWEEN 1000 AND 10000 THEN salary * 0.76
      ELSE salary * 0.51
    END
  ) AS salary
FROM SalariesWithMaxSalary;
