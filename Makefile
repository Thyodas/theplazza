##
## EPITECH PROJECT, 2022
## B-CCP-400-STG-4-1-theplazza-remi.mergen
## File description:
## Makefile
##

OBJ1 := main.o \
		Core.o \
		Mutex/Mutex.o \
		Shell/Shell.o \
		Thread/Thread.o \
		Kitchen/Kitchen.o \
		Cook/Cook.o \
		Config/Config.o \
		PizzaFactory/PizzaFactory.o \


C_FLAGS := -Wall -Wextra -g -std=c++2a
CC := g++
RM := rm
LINKFLAGS := -lguru

SRC_PATH := ./source/
OBJ_PATH := ./obj/
LIB_PATH := -L ./lib/external
INC_PATH := -I ./include

NAME := plazza

OBJ := $(patsubst %, $(OBJ_PATH)%, $(OBJ1))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
				@mkdir -p $(dir $@)
				@echo [CC] $<
				@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)

$(NAME):      $(OBJ)
				make -C lib/external
				@echo [INFO] Creating Binary Executable [$(NAME)]
				@$(CC) -o $@ $^ $(LIB_PATH) $(LINKFLAGS)

clean:
				@echo "[Cleaning]"
				make clean -C lib/external
				@$(RM) -rfv $(OBJ_PATH)*

fclean:
				make clean
				make fclean -C lib/external
				@$(RM) -rfv $(NAME)

re: fclean all

.PHONY: all clean fclean re cli
