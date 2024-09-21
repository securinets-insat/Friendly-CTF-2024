FROM php:8.3-apache

RUN a2enmod rewrite

RUN mkdir /var/www/html/uploads

COPY . /var/www/html/

RUN mv /var/www/html/flag.txt /flag.txt

RUN chown -R root:www-data /var/www/html /flag.txt && \
    chmod -R 750 /var/www/html && \
    chmod -R 730 /var/www/html/uploads && \
    chmod 740 /flag.txt 

EXPOSE 80

USER www-data

CMD ["apache2-foreground"]
