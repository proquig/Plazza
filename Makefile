##
## Makefile for PSU_2015_lemipc in /home/pogam-_g/ClionProjects/PSU_2015_lemipc
##
## Made by Gauthier POGAM--LE MONTAGNER
## Login   <pogam-_g@epitech.net>
##
## Started on  Sat Mar 19 15:12:40 2016 Gauthier POGAM--LE MONTAGNER
## Last update Sun Mar 27 19:29:11 2016 DROUARD Benjamin
##

DEBUG	= yes

DETAILS	= no

CC	= g++

RM	= rm -f

CFLAGS	+= -Wextra -Wall
CFLAGS	+= -std=c++11

ifeq ($(DEBUG),yes)
	CFLAGS	+= -g
endif

LDFLAGS	+= -lpthread

NAME	= plazza

OBJDIR = obj

SRCS	= src/orders/AOrder.cpp				\
          src/orders/EmailAddress.cpp			\
          src/orders/IpAddress.cpp			\
          src/orders/PhoneNumber.cpp			\
          src/process/Process.cpp			\
          src/utils/Decrypt.cpp				\
          src/utils/Exception.cpp			\
          src/utils/Fifo.cpp				\
          src/utils/Fork.cpp				\
          src/utils/Parser.cpp				\
          src/utils/ThreadPool.cpp			\
          src/Main.cpp					\
          src/OrderReader.cpp

OBJS	= $(SRCS:src/%.cpp=$(OBJDIR)/%.cpp.o)

all:	pre-build $(NAME)

pre-build:
	@echo "Start compilation of $(NAME)."
	@echo "Options :"
	@echo -e "\tDebug:\t\t$(DEBUG)"
	@echo -e "\tDetails:\t$(DETAILS)"
	@echo -e "\tCFLAGS:\t\t$(CFLAGS)"
	@echo -e "\tLDFLAGS:\t$(LDFLAGS)"
	@echo "Start objects compilation."

$(NAME):	$(OBJS)
	@echo -e "Linking $(NAME)."
ifeq ($(DETAILS),yes)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)
else
	@$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)
endif
	@echo "$(NAME) compiled."

$(OBJDIR)/%.cpp.o:	src/%.cpp
	@mkdir -p $(dir $@)
ifeq ($(DETAILS),yes)
	$(CC) $(CFLAGS) -c $< -o $@
else
	@echo -e "Compile:\t$<"
	@$(CC) $(CFLAGS) -c $< -o $@
endif

.NOTPARALLEL: fclean clean

.PHONY: clean fclean re

clean:
	@echo "Cleaning $(NAME)' object files..."
	@$(RM) $(OBJS)
	@$(RM) -r obj/
	@echo "$(NAME)' object files cleaned."

fclean:	clean
	@echo "Cleaning $(NAME)'..."
	@$(RM) $(NAME)
	@echo "$(NAME) cleaned."

re:	fclean all
