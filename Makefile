GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m

NAME				=	push_swap
BONUS_NAME			=	checker

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I $(INCLUDES)
SANITIZE			=	-g -fsanitize=address,undefined
RANDOM_MALLOC		=	-Xlinker --wrap=malloc
AR					=	ar rcs
RM					=	rm -rf

SRCS				=	apply_movs_to_b.c calc_nbr_movs_to_push.c \
						calculations.c find_spot_to_push.c input_checks.c \
						moves.c node_utils.c push_swap_operations.c \
						push_swap.c rev_rotate_operations.c \
						rotate_operations.c search_stacks.c stack_a_creation.c \
						#malloc.c
SRCS_PATH			=	srcs/

MAIN				=	$(SRCS_PATH)main.c
BONUS_MAIN			=	$(SRCS_PATH)checker.c

OBJ_DIR				=	objects
OBJS				=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
ALL_OBJS			=	objects/*.o

INCLUDES			=	includes/

LIBFT_PATH			=	complete_lib/libft/
LIBFT				=	$(LIBFT_PATH)libft.a
FT_PRINTF_PATH		=	complete_lib/ft_printf/
FT_PRINTF			=	$(FT_PRINTF_PATH)libftprintf.a
GNL_PATH			=	complete_lib/get_next_line/
GNL					=	$(GNL_PATH)libgnl.a
PERSONAL_LIBS		=	-lft -lgnl -lftprintf

TOTAL_SRCS          =   $(words $(SRCS))
TOTAL_OBJS          =   $(words $(wildcard $(OBJ_DIR)*))
FILES				=	0

$(OBJ_DIR)/%.o:		$(SRCS_PATH)%.c
					@$(CC) $(CFLAGS) -I /usr/local/include -c $< -o $@ && \
					$(eval FILES=$(shell echo $$(($(FILES) + 1)))) \
					$(call PRINT_PROGRESS,$(TOTAL_SRCS),$(GRN),$(YELLOW)Compiling$(DEFAULT) $@)

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(LIBFT) $(FT_PRINTF) $(GNL) $(OBJS)
					@$(CC) $(CFLAGS) $(MAIN) $(OBJS) -L$(LIBFT_PATH) -L$(GNL_PATH) -L$(FT_PRINTF_PATH) $(PERSONAL_LIBS) -o $(NAME)
					@echo "\033[2F\033[0K$(CYAN)$(NAME)$(DEFAULT) successfully created\033[E"
					@if norminette | grep -q -v "OK!"; then \
						norminette | grep -v OK!; echo "Norminette has$(RED) errors!$(DEFAULT)"; \
					else \
						echo "Norminette$(GRN) OK!!$(DEFAULT)"; \
					fi
					

bonus:				$(NAME)
					@$(CC) $(CFLAGS) $(BONUS_MAIN) $(OBJS) -L$(LIBFT_PATH) -L$(GNL_PATH) -L$(FT_PRINTF_PATH) $(PERSONAL_LIBS) -o $(BONUS_NAME)
					@echo "$(CYAN)$(BONUS_NAME)$(DEFAULT) successfully created"

$(LIBFT):
					@make -s -C $(LIBFT_PATH) all

$(FT_PRINTF):
					@make -s -C $(FT_PRINTF_PATH) all

$(GNL):
					@make -s -C $(GNL_PATH) all

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

clean:
					@$(foreach file,$(wildcard $(OBJ_DIR)*), \
						$(eval FILES=$(shell echo $$(($(FILES) + 1)))) \
						$(call PRINT_PROGRESS,$(TOTAL_OBJS),$(RED),$(YELLOW)Deleting$(DEFAULT) $(file)); \
						$(RM) $(file); \
					)
					@$(RM) $(OBJ_DIR)
					@echo "\033[2F\033[0K$(PURPLE)$(OBJ_DIR)$(DEFAULT) deleted\033[E"
					$(eval FILES=0)

fclean:				clean
					@$(RM) $(OBJ_DIR)
					@echo "$(PURPLE)$(OBJ_DIR)$(DEFAULT) deleted"
					@$(RM) $(LIBFT)
					@echo "$(PURPLE)$(LIBFT)$(DEFAULT) deleted"
					@$(RM) $(GNL)
					@echo "$(PURPLE)$(GNL)$(DEFAULT) deleted"
					@$(RM) $(FT_PRINTF)
					@echo "$(PURPLE)$(FT_PRINTF)$(DEFAULT) deleted"
					@$(RM) $(NAME)
					@echo "$(PURPLE)$(NAME)$(DEFAULT) deleted"
					@$(RM) $(BONUS_NAME)
					@echo "$(PURPLE)$(BONUS_NAME)$(DEFAULT) deleted"

re:					fclean all


.PHONY:				all bonus clean fclean re

define PRINT_PROGRESS
    if [ "$(FILES)" -eq "1" ]; then \
        printf "\033[0K$(3)\n["; \
    else \
        printf "\033[0K\033[1F\033[0K$(3)\n["; \
    fi
    @for i in `seq 1 $(shell expr $(FILES) \* 70 / $(1))`; do \
        printf "$(2)=\033[0m"; \
    done
    @for i in `seq 1 $(shell expr 70 - $(FILES) \* 70 / $(1))`; do \
        printf " "; \
    done
    @printf "] $(shell echo $$(($(FILES) * 100 / $(1))))%%"
	if [ "$(FILES)" -eq "$(1)" ]; then \
        printf "\n"; \
	fi
endef

CYAN				=	\033[36m
PURPLE				=	\033[35m
YELLOW				=	\033[33m
GRN					=	\033[32m
RED					=	\033[31m
DEFAULT				=	\033[0m