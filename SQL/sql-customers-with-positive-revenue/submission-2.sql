-- Write your query below
select customer_id
from Customers
where year = 2020
group by customer_id
having sum(revenue) > 0;
