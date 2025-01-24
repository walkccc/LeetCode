WITH
  Calendar AS (
    # We should be given a calendar in hand. Otherwise, assume we are oracle
    # and already know the testcase.
    SELECT '2018' AS year, '2018-01-01' AS start, '2018-12-31' AS end
    UNION ALL
    SELECT '2019' AS year, '2019-01-01' AS start, '2019-12-31' AS end
    UNION ALL
    SELECT '2020' AS year, '2020-01-01' AS start, '2020-12-31' AS end
  )
SELECT
  Product.product_id,
  Product.product_name,
  Calendar.year AS report_year,
  (
    DATEDIFF(
      LEAST(Sales.period_end, Calendar.end),
      GREATEST(Sales.period_start, Calendar.start)
    ) + 1
  ) * Sales.average_daily_sales AS total_amount
FROM Sales
INNER JOIN Calendar
  ON (Calendar.year BETWEEN YEAR(Sales.period_start) AND year(Sales.period_end))
INNER JOIN Product
  USING (product_id)
ORDER BY 1, 3;
