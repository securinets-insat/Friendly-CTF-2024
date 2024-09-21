FROM php:8.3-apache

RUN a2enmod rewrite


COPY . /var/www/html/


WORKDIR /var/www/html

RUN chown -R root:www-data /var/www/html && \
    chmod -R 750 /var/www/html && \
	chmod 740 /var/www/html/flag.txt 

EXPOSE 80

USER www-data

CMD ["apache2-foreground"]

