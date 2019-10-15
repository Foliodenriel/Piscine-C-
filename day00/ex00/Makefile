NAME = megaphone

SRC = megaphone.cpp

FLAGS = -Wall -Wextra -Werror

CPP = clang++

all: $(NAME)

$(NAME):
	$(CPP) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re