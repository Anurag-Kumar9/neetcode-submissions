select c.customer_id, c.customer_name
from customers c
right join orders o
on o.customer_id = c.customer_id
group by c.customer_id, c.customer_name
having 
    sum((o.product_name = 'A')::int) > 0
    and sum((o.product_name = 'B')::int) > 0
    and sum((o.product_name = 'C')::int) = 0
order by c.customer_name;
