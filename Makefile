SRC =	src/main.c

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = -I include

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

TARGET = test

.c.o:
	$(CC) $(C_FLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(C_FLAGS) -o $(TARGET) $(OBJ) $(LIB_FLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
