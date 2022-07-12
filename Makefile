NAME = push_swap

.PHONY: all bonus fclean clean re

$(NAME):
	gcc -Wall -Werror -Wextra ft_push_swap.c ft_utils.c ft_utils2.c ft_utils3.c ft_assign.c ft_low_sorts.c ft_low_utils.c ft_quick_sort.c ft_a_2_b_start.c ft_b_2_a_finish.c -o $(NAME)

all:	$(NAME)

bonus:
	gcc -Wall -Werror -Wextra ft_bonus.c ft_utils.c ft_utils2.c ft_utils3.c ft_assign.c ft_a_2_b_start.c ft_bonus_utils.c -o checker

clean:
	@if [ -f "${NAME}" ]; then\
		rm ${NAME};\
		printf "rm %s\n" "${NAME}";\
	else\
		printf "%s Doesn't Exist so It Cannot Be Removed\n" "${NAME}";\
	fi

fclean:	clean
	@if [ -f "checker" ]; then\
		rm checker;\
		printf "rm checker\n";\
	else\
		printf "checker Doesn't Exist so It Cannot Be Removed\n";\
	fi

re:		fclean all bonus