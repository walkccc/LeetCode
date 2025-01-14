WITH
  YearlyOrders AS (
    SELECT
      customer_id,
      YEAR(order_date) AS year,
      SUM(price) AS price
    FROM Orders
    GROUP BY 1, 2
  )
SELECT CurrYear.customer_id
FROM YearlyOrders AS CurrYear
LEFT JOIN YearlyOrders AS NextYear
  ON (
    CurrYear.customer_id = NextYear.customer_id
    AND CurrYear.year + 1 = NextYear.year
    AND CurrYear.price < NextYear.price)
GROUP BY 1
HAVING COUNT(*) - COUNT(NextYear.customer_id) = 1;
