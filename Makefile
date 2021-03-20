
SRC		=	ft_printf.c ft_check_flags.c \
			\
			./print_type/ft_print_type.c ./print_type/print_address.c \
			./print_type/print_char.c ./print_type/print_hex.c \
			./print_type/print_int.c ./print_type/print_string.c \
			./print_type/print_uint.c ./print_type/while_print.c \
			\
			./str_uteis/ft_init_struct.c ./str_uteis/ft_isdigit.c \
			./str_uteis/ft_isspace.c ./str_uteis/ft_numdigt.c \
			./str_uteis/ft_putchar_fd.c ./str_uteis/ft_strlen.c	\
			./str_uteis/ft_toupper.c \
			\
			./num_to_str/ft_atoi.c ./num_to_str/ft_utoa_base.c \
			./num_to_str/ft_utoa.c

OBJ		=	${SRC:.c=.o}
#--------------------------------------//---------------------------------------
NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

CC		=	clang
#--------------------------------------//---------------------------------------
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "  Criando .o de "$<
#--------------------------------------//---------------------------------------
all:		$(NAME)

$(NAME):	$(OBJ) ft_printf.h
	@ar -rcs $(NAME) $(OBJ)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|          ft_printf.a criada          |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------
clean:
	@rm -f $(OBJ) $(OBJ_B) a.out
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o deletados         |"
	@echo "\\ ************************************ /"
	@echo ""

fclean:		clean
	@rm -f $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|         ft_printf.a deletada         |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"
	git push

.PHONY:		all clean fclean re git
