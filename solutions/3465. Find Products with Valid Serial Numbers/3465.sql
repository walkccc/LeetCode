SELECT product_id, product_name, description
FROM Products
WHERE
  description REGEXP 'SN[0-9]{4}-[0-9]{4}$'
  OR description REGEXP 'SN[0-9]{4}-[0-9]{4}[^0-9]+'
ORDER BY 1;
