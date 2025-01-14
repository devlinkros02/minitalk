# Main Makefile

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Add the path to the header files
INCLUDES = -I $(LIBFT_DIR)

all: client server

# Rule to make the library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile the client program and link with libft.a
client: $(LIBFT) client.o
	$(CC) $(CFLAGS) -o $@ client.o $(LIBFT)

client.o: client.c
	$(CC) $(CFLAGS) $(INCLUDES) -c client.c -o $@

# Rule to compile the server program and link with libft.a
server: $(LIBFT) server.o
	$(CC) $(CFLAGS) -o $@ server.o $(LIBFT)

server.o: server.c
	$(CC) $(CFLAGS) $(INCLUDES) -c server.c -o $@

clean:
	rm -f client.o server.o client server
	$(MAKE) -C $(LIBFT_DIR) fclean

re: clean all

.PHONY: all clean
