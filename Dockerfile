# syntax=docker/dockerfile:1

FROM alpine:3.14
WORKDIR /exe
COPY ./node.out ./
CMD ["./node.out"]
