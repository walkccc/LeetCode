WITH
  SellerToPrice AS (
    SELECT seller_id, SUM(price) AS price
    FROM Sales
    GROUP BY 1
  )
SELECT seller_id
FROM SellerToPrice
WHERE price = (
    SELECT MAX(price)
    FROM SellerToPrice
  );
