SELECT
  Products.product_id,
  Products.price - (
    Products.price * IFNULL(Discounts.discount, 0) / 100
  ) AS final_price,
  Products.category
FROM Products
LEFT JOIN Discounts
  USING (category);
