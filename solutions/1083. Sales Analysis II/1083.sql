SELECT Sales.buyer_id
FROM Sales
INNER JOIN Product
  USING (product_id)
GROUP BY 1
HAVING
  SUM(Product.product_name = 'S8') > 0
  AND SUM(Product.product_name = 'iPhone') = 0;
