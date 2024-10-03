# Use the official PHP image with Apache
FROM php:8.1-apache

# Install PDO and other extensions needed
RUN docker-php-ext-install mysqli pdo pdo_mysql
# Copy source code into the container
COPY src/ /var/www/html/

# Set the working directory
WORKDIR /var/www/html/

# Expose port 80
EXPOSE 80
