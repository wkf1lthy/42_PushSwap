NAME = push_swap
INCLUDES = includes/
SRC_DIR = src/

OBJ_DIR = obj/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
PRFLAGS     = -ldl -lglfw -pthread -lm
RM          = rm -rf

LIBFT_DIR = $(INCLUDES)libft/
LIBFT = $(LIBFT_DIR)libft.a

MOVES_DIR = moves/
MOVES = push reverse_rotate rotate swap

SORT_DIR = sort/
SORT = radix simple_sort sort

UTILS_DIR = utils/
UTILS = check_args index print_list t_stack utils

SRC_FILES = main
SRC_FILES  += $(addprefix $(MOVES_DIR), $(MOVES))
SRC_FILES  += $(addprefix $(SORT_DIR), $(SORT))
SRC_FILES  += $(addprefix $(UTILS_DIR), $(UTILS))


SRC         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


OBJ_CACHE   = .cache_exists

all: 			 $(LIBFT) $(NAME)

bonus: 			$(LIBFT) $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) CFLAGS+=$(LIBFT_CFLAGS)

$(NAME): 		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "\033[0;32m$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(MOVES_DIR)
					@mkdir -p $(OBJ_DIR)$(SORT_DIR)
					@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

clean:
					@make clean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)
					$(RM) $(OBJ_CACHE)
					@echo "push_swap and libs object files cleaned!"

fclean: 		clean
					@make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME) $(BONUS_NAME)
					@echo "push_swap and libs executable files cleaned!"

re: 			fclean all
					@echo "Cleaned and rebuilt everything for push_swap!"


.PHONY:			all clean fclean re

.SILENT: