WITH
  CurrMonth AS (
    SELECT
      *,
      MAX(month) OVER(PARTITION BY id) AS max_month
    FROM Employee
  )
SELECT
  CurrMonth.id,
  CurrMonth.month,
  SUM(PrevMonth.salary) AS salary
FROM CurrMonth
INNER JOIN Employee AS PrevMonth
  ON (CurrMonth.id = PrevMonth.id AND CurrMonth.month - PrevMonth.month BETWEEN 0 AND 2)
WHERE CurrMonth.month != CurrMonth.max_month
GROUP BY 1, 2
ORDER BY 1, 2 DESC;
