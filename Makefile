DEBUG		= yes

DETAILS		= no

C++		= g++

RM		= rm -f

CXXFLAGS	+= -Wextra -Wall -I ./include/
CXXFLAGS	+= -std=c++11
CXXFLAGS	+= -pthread

ifeq ($(DEBUG),yes)
	CXXFLAGS	+= -g
endif

LDFLAGS	+= -pthread

NAME	= plazza

OBJDIR = obj

SRCS	= src/orders/AOrder.cpp				\
	  src/orders/EmailAddress.cpp			\
	  src/orders/IpAddress.cpp			\
	  src/orders/PhoneNumber.cpp			\
	  src/process/OrderDispatcher.cpp		\
	  src/process/Process.cpp			\
	  src/utils/Decrypt.cpp				\
	  src/utils/Exception.cpp			\
	  src/utils/Fifo.cpp				\
	  src/utils/Fork.cpp				\
	  src/utils/Parser.cpp				\
	  src/utils/Regex.cpp				\
	  src/Main.cpp					\
	  src/OrderReader.cpp

OBJS	= $(SRCS:src/%.cpp=$(OBJDIR)/%.cpp.o)

all:	pre-build $(NAME)

pre-build:
	@echo "Start compilation of $(NAME)."
	@echo "Options :"
	@echo -e "\tDebug:\t\t$(DEBUG)"
	@echo -e "\tDetails:\t$(DETAILS)"
	@echo -e "\tCompiler:\t$(C++)"
	@echo -e "\tCXXFLAGS:\t$(CXXFLAGS)"
	@echo -e "\tLDFLAGS:\t$(LDFLAGS)"
	@echo "Start objects compilation."

$(NAME):	$(OBJS)
	@echo -e "Linking $(NAME)."
ifeq ($(DETAILS),yes)
	$(C++) $(LDFLAGS) $(OBJS) -o $(NAME)
else
	@$(C++) $(LDFLAGS) $(OBJS) -o $(NAME)
endif
	@echo "$(NAME) compiled."

$(OBJDIR)/%.cpp.o:	src/%.cpp
	@mkdir -p $(dir $@)
ifeq ($(DETAILS),yes)
	$(C++) $(CXXFLAGS) -c $< -o $@
else
	@echo -e "Compile:\t$<"
	@$(C++) $(CXXFLAGS) -c $< -o $@
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
