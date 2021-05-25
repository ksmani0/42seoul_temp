#wordpress_setup.sh: COPY wordpress_setup.sh /usr/sbin/wordpress_setup.sh
chmod -R 755 /var/www/*

mkdir -p /var/www/html
touch /var/www/html/index.php

#After creating index.php, redirect to phpmyadmin.
echo "<?php phpinfo(); ?>" >> /var/www/html/index.php

mkdir -p /etc/nginx/sites-available/
mkdir -p /etc/nginx/sites-enabled/

#mysql -hserver -uid -ppassword < Sql file to run
mysql -hmysql -Dwordpress -uuser -ppass < /run/nginx/wordpress.sql
