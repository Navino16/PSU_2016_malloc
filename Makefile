##
## Makefile for malloc in /home/jaunet_n/Rendu/PSU_2016_malloc
##
## Made by Nathan Jaunet
## Login   <jaunet_n@epitech.net>
##
## Started on Mon Jan 30 09:24:28 CET 2017 Nathan Jaunet
## Last update Sat Feb 11 13:20:33 2017 Nathan Jaunet
##

NAME	=	libmy_malloc.so

SRCS	=	sources/malloc.c		\
		sources/free.c			\
		sources/realloc.c		\
		sources/show_alloc_mem.c	\
		sources/calloc.c

OBJS	=	$(SRCS:.c=.o)

INCS	=	-I./include

LIBS	=

CFLAGS	=	$(INCS) $(LIBS)

CC	=	gcc -fPIC -shared -g

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

