CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/Main.c
OUT = Main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)