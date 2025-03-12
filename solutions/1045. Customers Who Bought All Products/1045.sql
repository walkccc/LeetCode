SELECT customer_id
FROM Customer
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*) FROM Product
  );
