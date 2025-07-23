WITH
  YearlySpends AS (
    SELECT
      product_id,
      YEAR(transaction_date) AS year,
      SUM(spend) AS spend
    FROM user_transactions
    GROUP BY 1, 2
  )
SELECT
  CurrYear.year,
  CurrYear.product_id,
  CurrYear.spend AS curr_year_spend,
  PrevYear.spend AS prev_year_spend,
  ROUND(100 * (CurrYear.spend - PrevYear.spend) / PrevYear.spend, 2) AS yoy_rate
FROM YearlySpends AS CurrYear
LEFT JOIN YearlySpends AS PrevYear
  ON (
    CurrYear.product_id = PrevYear.product_id
    AND CurrYear.year - 1 = PrevYear.year)
ORDER BY product_id, year;
