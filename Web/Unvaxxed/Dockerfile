FROM php:7.4-alpine as base

RUN addgroup -S appgroup && adduser -S appuser -G appgroup

WORKDIR /app

COPY --chown=appuser:appgroup src /app
COPY --chown=appuser:appgroup patients /patients
COPY --chown=appuser:appgroup doctors /doctors
COPY --chown=appuser:appgroup flag /flag

RUN chmod 440 /flag /patients /doctors && \
    chown appuser:appgroup /flag /patients /doctors

USER appuser

EXPOSE 8000

CMD ["php", "-S", "0.0.0.0:8000"]
