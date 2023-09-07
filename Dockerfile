FROM gcc:13.2.0

RUN apt-get update -y && apt-get install gdb -y

WORKDIR /app