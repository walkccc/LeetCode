SELECT
  WEEK(purchase_date, 1) - WEEK('2023-11-01', 1) + 1 AS week_of_month,
  purchase_date,
  SUM(amount_spend) AS total_amount
FROM Purchases
WHERE
  DAYOFWEEK(purchase_date) = 6
  AND MONTH(purchase_date) = 11
  AND YEAR(purchase_date) = 2023
GROUP BY purchase_date
ORDER BY week_of_month;
