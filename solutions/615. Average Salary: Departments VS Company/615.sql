WITH
  AvgSalary AS (
    SELECT DISTINCT
      DATE_FORMAT(pay_date, '%Y-%m') AS pay_month,
      Employee.department_id,
      AVG(amount) OVER(
        PARTITION BY Employee.department_id,
        Salary.pay_date
      ) AS department_avg_salary,
      AVG(amount) OVER(PARTITION BY Salary.pay_date) AS company_avg_salary
    FROM Salary
    INNER JOIN Employee
      USING (employee_id)
  )
SELECT DISTINCT
  pay_month,
  department_id,
  (
    CASE
      WHEN department_avg_salary > company_avg_salary THEN 'higher'
      WHEN department_avg_salary < company_avg_salary THEN 'lower'
      ELSE 'same'
    END
  ) AS comparison
FROM AvgSalary;
