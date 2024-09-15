FROM php:alpine
# Used php 8.3.11

RUN apk add --no-cache \
    php-fileinfo \
    php-mysqli \
    php-openssl

# Disable debugging
# RUN echo "display_errors = Off" >> /usr/local/etc/php/conf.d/disable_debug.ini && \
# echo "error_reporting = 0" >> /usr/local/etc/php/conf.d/disable_debug.ini && \
# echo "display_startup_errors = Off" >> /usr/local/etc/php/conf.d/disable_debug.ini && \
# echo "xdebug.remote_enable = 0" >> /usr/local/etc/php/conf.d/disable_debug.ini && \
# echo "xdebug.default_enable = 0" >> /usr/local/etc/php/conf.d/disable_debug.ini

RUN mkdir /var/www/html/uploads

COPY . /var/www/html/

RUN mv /var/www/html/flag.txt /flag.txt

RUN chown -R root:www-data /var/www/html /flag.txt && \
    chmod -R 750 /var/www/html && \
    chmod -R 730 /var/www/html/uploads && \
    chmod 740 /flag.txt 

RUN echo "disable_functions = exec,passthru,shell_exec,system,unlink,phpinfo,show_source,highlight_file,popen,proc_open,fopen_with_path,dbmopen,dbase_open,putenv,filepro,filepro_rowcount,filepro_retrieve,posix_mkfifo" >> /usr/local/etc/php/conf.d/disable_functions.ini

EXPOSE 80

USER www-data

CMD ["php", "-S", "0.0.0.0:80", "-t", "/var/www/html"]
