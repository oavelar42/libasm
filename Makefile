NAME	=	libasm.a
NAME	=	nasm
FLAGS	=	-Wall -Wextra -Werror
NFLAGS	=	-f elf64
DEBUG	=	-g -F dwarf
SRCS	=	./ft_strlen.s \
			./ft_strcpy.s \
			./ft_strcmp.s \
			./ft_write.s \
			./ft_read.s \
			./ft_strdub.s
OBJS	= 	
$(SRCS:.s=.o)

%.o:	%.s
			$(NA) $(DEBUG) $(NFLAGS) $<

all:	$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $^
				@echo "----- libasm.a built! -----"
clean:
				rm -rf $(OBJS)
				@echo "----- objects removed! -----"

fclean:			clean
				rm -rf $(NAME)
				rm -rf exe
				@echo "----- all cleared ! -----"

re:				fclean all

exe:			$(NAME)
				gcc $(FLAGS) main.c $(NAME) -o exe
				@echo "----- all ready! -----"

exedebug:		$(NAME)
				gcc $(FLAGS) $(DEBUG)
				main.c $(NAME) -o exe
				@echo "----- debug exe ready! -----"
		
.PHONY:			all clean fclean re exe exedebug