
NAME		= megaphone

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g #-pedantic

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f

%.o:		%.cpp Makefile
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