WITH
  ProductToYear AS (
    SELECT product_id, MIN(year) AS year
    FROM Sales
    GROUP BY 1
  )
SELECT
  Sales.product_id,
  ProductToYear.year AS first_year,
  Sales.quantity,
  Sales.price
FROM Sales
INNER JOIN ProductToYear
  USING (product_id, year);
