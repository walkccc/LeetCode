SELECT product_id, name
FROM Products
WHERE
  name REGEXP '[^0-9][0-9]{3}[^0-9]'
  OR name REGEXP '^[0-9]{3}[^0-9]'
  OR name REGEXP '[^0-9][0-9]{3}$'
ORDER BY 1;
