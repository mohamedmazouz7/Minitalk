SERVER = server
CLIENT = client
SERVERBONUS = server_bonus
CLIENTBONUS = client_bonus

SSERVER = server.c
SCLIENT = client.c 

SSBONUS = server_bonus.c
CSBONUS = client_bonus.c

CFLAGS = -Wall -Wextra -Werror
CC = cc 


all: $(SERVER) $(CLIENT)

$(SERVER): $(SSERVER)
	$(CC) $(CFLAGS) $(SSERVER) -Lft_printf -lftprintf -o $(SERVER)

$(CLIENT): $(SCLIENT)
	$(CC) $(CFLAGS) $(SCLIENT) -Lft_printf -lftprintf -o $(CLIENT)

bonus: $(SERVERBONUS) $(CLIENTBONUS)

$(SERVERBONUS): $(SSBONUS)
	$(CC) $(CFLAGS) $(SSBONUS) -Lft_printf -lftprintf -o $(SERVERBONUS)

$(CLIENTBONUS): $(CSBONUS)
	$(CC) $(CFLAGS) $(CSBONUS) -Lft_printf -lftprintf -o $(CLIENTBONUS)

clean:

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVERBONUS) $(CLIENTBONUS)

re: fclean all