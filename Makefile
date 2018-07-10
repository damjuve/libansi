NAME		=	libansi
CC		= 	gcc
RM		=	rm -rf
AR		=	ar

CFLAGS		=	-std=c99 -Wall -Wextra -Werror
IFLAGS		=	-I./inc

SRCS		=	src/clear.c \
			src/color.c \
			src/config.c \
			src/cursor.c \
			src/global.c \
			src/matrix.c \
			src/print.c

OBJS		=	$(SRCS:.c=.o)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(AR) rcs $(NAME).a $(OBJS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NANE).a

re		:	fclean all
