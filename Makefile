NAME_1 = push_swap
NAME_2 = checker

HEADER = push_swap.h
HEAD_DIR = inc/

OPTFLAGS = -O2
CC	= cc

CFLAGS	= -Wall -Wextra -Werror $(OPTFLAGS)

SRCS_1 = main_push_swap.c \
		 support_standart.c \
		 support_print.c \
		 support_get_argv.c \
		 support_split.c \
		 support_lists.c \
		 support_argv.c \
		 start_sort_and_checker.c \
		 support_init_add_del_list.c \
		 sort_three.c \
		 sort_four_a.c \
		 sort_five.c \
		 command_sa_sb_ss.c \
		 command_pa_pb.c \
		 command_ra_rb_rr.c \
		 command_rra_rrb_rrr.c \
		 support_fill_command.c \
		 support_check_command.c \
		 sort_big.c \
		 support_lot.c \
		 support_check_next_elem.c \

SRCS_2 = main_checker.c \
		 support_standart.c \
		 support_print.c \
		 support_get_argv.c \
		 support_split.c \
		 support_lists.c \
		 support_argv.c \
		 start_sort_and_checker.c \
		 support_init_add_del_list.c \
		 sort_three.c \
		 sort_four_a.c \
		 sort_five.c \
		 command_sa_sb_ss.c \
		 command_pa_pb.c \
		 command_ra_rb_rr.c \
		 command_rra_rrb_rrr.c \
		 support_fill_command.c \
		 support_check_command.c \
		 sort_big.c \
		 support_lot.c \
		 support_check_next_elem.c \
		 gnl.c \
         gnl_utils.c

SRC_DIR = src/
SRCS_DIR_1 = $(SRC_DIR)push_swap/
SRCS_DIR_2 = $(SRC_DIR)checker/

OBJ_1 = $(patsubst %.c,%.o,$(SRCS_1))
OBJ_2 = $(patsubst %.c,%.o,$(SRCS_2))
OBJ_DIR = obj/
OBJ_DIR_1 = $(OBJ_DIR)push_swap/
OBJ_DIR_2 = $(OBJ_DIR)checker/
OBJS_1 = $(addprefix $(OBJ_DIR_1), $(OBJ_1))
OBJS_2 = $(addprefix $(OBJ_DIR_2), $(OBJ_2))

all:	$(NAME_1)

bonus: all $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJS_1) Makefile
		$(CC) $(CFLAGS) $(OBJS_1) -o $(NAME_1)

$(NAME_2): $(OBJS_2) Makefile
		$(CC) $(CFLAGS) $(OBJS_2) -o $(NAME_2)

$(OBJ_DIR_1)%.o: $(SRCS_DIR_1)%.c $(HEAD_DIR)$(HEADER)
		@mkdir -p $(OBJ_DIR_1)
		$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD_DIR)

$(OBJ_DIR_2)%.o: $(SRCS_DIR_2)%.c $(HEAD_DIR)$(HEADER)
		@mkdir -p $(OBJ_DIR_2)
		$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD_DIR)

RM	= rm -Rf

clean:
		$(RM) $(OBJS_1) $(OBJS_2)
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME_1) $(NAME_2)

re: fclean all bonus

.PHONY: all bonus clean fclean re
