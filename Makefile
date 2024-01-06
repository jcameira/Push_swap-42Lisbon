GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m

NAME				=	push_swap.a
EXEC_NAME			=	push_swap
BONUS_EXEC_NAME		=	checker

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
AR					=	ar rcs
RM					=	rm -rf

SRCS				=	apply_movs_to_b.c calc_nbr_movs_to_push.c \
						calculations.c find_spot_to_push.c input_checks.c \
						moves.c node_utils.c push_swap_operations.c \
						push_swap.c rev_rotate_operations.c \
						rotate_operations.c search_stacks.c stack_a_creation.c \
						stack_a_creation.c
SRCS_PATH			=	srcs/

MAIN				=	$(SRCS_PATH)main.c
BONUS_MAIN			=	$(SRCS_PATH)checker.c

OBJ_DIR				=	objects
OBJS				=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
ALL_OBJS			=	objects/*.o


LIBFT_PATH			=	complete_lib/libft
LIBFT				=	$(LIBFT_PATH)/libft.a
FT_PRINTF_PATH		=	complete_lib/ft_printf
FT_PRINTF			=	$(FT_PRINTF_PATH)/libftprintf.a
GET_NEXT_LINE_PATH	=	complete_lib/get_next_line
GET_NEXT_LINE		=	$(GET_NEXT_LINE_PATH)/get_next_line.a

$(OBJ_DIR)/%.o:		$(SRCS_PATH)%.c
					@$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME) $(EXEC_NAME)

$(NAME):			$(OBJ_DIR) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(OBJS)
					@$(AR) $(NAME) $(ALL_OBJS)
					@echo "$(GREEN) Arquive for push_swap created!$(DEFAULT)"
					@if norminette | grep -q -v "OK!"; then \
						norminette; echo "$(RED) Norminette has errors!$(DEFAULT)"; \
					else \
						echo "$(GREEN) Norminette OK!!$(DEFAULT)"; \
					fi
					

bonus:				$(NAME) $(BONUS_EXEC_NAME)

$(EXEC_NAME):
					@$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(EXEC_NAME)
					@echo "$(GREEN) $(EXEC_NAME) executable created!$(DEFAULT)"

$(BONUS_EXEC_NAME):
					@$(CC) $(CFLAGS) $(BONUS_MAIN) $(NAME) -o $(BONUS_EXEC_NAME)
					@echo "$(GREEN) $(BONUS_EXEC_NAME) executable created!$(DEFAULT)"

$(LIBFT):
					@make -s -C $(LIBFT_PATH) all
					@echo "$(GREEN) Arquive for libft created!$(DEFAULT)"

$(FT_PRINTF):
					@make -s -C $(FT_PRINTF_PATH) all
					@echo "$(GREEN) Arquive for ft_printf created!$(DEFAULT)"

$(GET_NEXT_LINE):
					@make -s -C $(GET_NEXT_LINE_PATH) all
					@echo "$(GREEN) Arquive for get_next_line created!$(DEFAULT)"

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@echo "$(GREEN) $(OBJ_DIR) directory created!$(DEFAULT)"

clean:
					@$(RM) $(OBJ_DIR)
					@echo "$(RED) All objects and objects diretory removed!$(DEFAULT)"

fclean:				clean
					@$(RM) $(EXEC_NAME)
					@$(RM) $(BONUS_EXEC_NAME)
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(FT_PRINTF)
					@$(RM) $(GET_NEXT_LINE)
					@echo "$(RED) All arquives and executable removed!$(DEFAULT)"

re:					fclean all


.PHONY:				all bonus clean fclean re bonus nothing_message