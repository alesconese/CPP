
NAME		= violence

SRCS		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
INC			= Weapon.hpp HumanA.hpp HumanB.hpp

CC			= g++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -pedantic #-fsanitize=address 
RM			= rm -f

OBJS		= $(SRCS:.cpp=.o)

%.o:		%.cpp Makefile $(INC)
				@$(CC) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re