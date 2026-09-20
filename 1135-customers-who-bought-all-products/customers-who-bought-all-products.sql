# Write your MySQL query statement below
SELECT customer_id
FROM (
    SELECT customer_id
    FROM Customer
    GROUP BY customer_id
    HAVING COUNT(DISTINCT Customer.product_key)=(SELECT COUNT(Product.product_key) FROM Product)
)   AS temp