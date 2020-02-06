# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <umoff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 21:26:14 by umoff             #+#    #+#              #
#    Updated: 2020/02/06 11:46:03 by umoff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc -g#-Wall -Wextra -Werror
SRC_DIR = srcs/
LIBFT_DIR = libft/
OBJ_DIR = obj/
PS_SRCS = ft_sort_a.c ft_sort_b.c ft_lstcom.c ft_pa_pb_ra_rb_rr.c ft_sa_sb_rra_rrb_rrr.c ft_init_ps.c \
ft_check_sort.c ft_calc_max.c ft_fill_order.c ft_for_three.c ft_print_com.c ft_push_swap.c ft_for_five.c \
ft_parse.c ft_free_all.c ft_first_sort.c ft_utils.c
CHECKER_SRCS = ft_checker.c ft_sa_sb_rra_rrb_rrr.c ft_init_ps.c ft_lstcom.c ft_check_sort.c ft_fill_order.c \
ft_pa_pb_ra_rb_rr.c ft_parse.c ft_free_all.c ft_utils.c

CHECKER_OBJ = ${CHECKER_SRCS:c=o}
PS_OBJ = ${PS_SRCS:c=o}

all: $(CHECKER) $(PUSH_SWAP)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I libft/ -I include/ -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@make -C libft/
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -I includes/ -o $(CHECKER)
	@echo "\033[34m$(CHECKER)   was compiled\033[m"

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -o $(PUSH_SWAP)
	@echo "\033[34m$(PUSH_SWAP) was compiled\033[m"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(CHECKER)
	@echo "\033[31m$(CHECKER)   was deleted"
	@rm -f $(PUSH_SWAP)
	@echo "$(PUSH_SWAP) was deleted\033[m"

re: fclean all