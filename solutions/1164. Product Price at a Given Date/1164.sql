WITH
  RankedProducts AS (
    SELECT
      product_id,
      new_price,
      RANK() OVER(
        PARTITION BY product_id
        ORDER BY change_date DESC
      ) AS `rank`
    FROM Products
    WHERE change_date <= '2019-08-16'
  ),
  ProductToLatestPrice AS (
    SELECT product_id, new_price
    FROM RankedProducts
    WHERE `rank` = 1
  )
SELECT
  Products.product_id,
  IFNULL(ProductToLatestPrice.new_price, 10) AS price
FROM Products
LEFT JOIN ProductToLatestPrice
  USING (product_id)
GROUP BY 1;
