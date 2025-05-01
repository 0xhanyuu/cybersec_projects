# compiler information
CC = g++
CFLAGS = -Wall -Wextra

# directories
SRCDIR = src/

# files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# target binary
TARGET = xorcrypt

# create executable
all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# remove files
clean:
	rm -f $(TARGET)

.PHONY: clean
