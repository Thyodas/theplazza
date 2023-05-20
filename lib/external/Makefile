##
## EPITECH PROJECT, 2022
## B-CCP-400-STG-4-1-theplazza-remi.mergen
## File description:
## Makefile
##

OBJ1 = loguru.o

OBJ_PATH = obj/

RM := rm

INC_PATH := -I ../../include

OBJ := $(patsubst %, $(OBJ_PATH)%, $(OBJ1))

NAME = libguru.a

all:
	@$(MAKE) -s $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
				@mkdir -p $(dir $@)
				@echo [CC] $<
				@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)

$(NAME):	$(OBJ)
			@echo [INFO] Creating library [$(NAME)]
			ar -rc $(NAME) $(OBJ_PATH)*

clean:
		@$(RM) -rfv $(OBJ_PATH)*

fclean:		clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv $(OBJ_PATH)

re:		fclean all

.PHONY:		all clean fclean re