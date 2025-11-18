NAME = bsp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

SRCS =	main.cpp \
		Point.cpp \
		Fixed.cpp \
		bsp.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re