WITH
  Dates AS (
    SELECT DISTINCT visited_on
    FROM Customer
    WHERE visited_on >= (
      SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
      FROM Customer
    )
  )
SELECT
  Dates.visited_on,
  SUM(Customer.amount) AS amount,
  ROUND(SUM(Customer.amount) / 7, 2) AS average_amount
FROM Dates
LEFT JOIN Customer
  ON (DATEDIFF(Dates.visited_on, Customer.visited_on) BETWEEN 0 AND 6)
GROUP BY 1;
