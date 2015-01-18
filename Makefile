
      #########.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##."

NAME = ft_gkrellm

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -O3

LDFLAGS = -lncurses

SRC = \
			main.cpp						\
			Monitor.cpp					\
			NCursesDisplay.cpp	\
			RamModule.cpp				\
			TextItem.cpp				\

OBJ = $(SRC:.cpp=.o)


# Colors
NO_COLOR     = \x1b[0m
OK_COLOR     = \x1b[32;01m
ERROR_COLOR  = \x1b[31;01m
WARN_COLOR   = \x1b[33;01m
SILENT_COLOR = \x1b[30;01m
ALIGN_TAB    = \e[25G


.PHONY: all re space clean fclean

all: $(NAME)

%.o: %.cpp
	@printf "$(SILENT_COLOR)$<$(NO_COLOR)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "$(ALIGN_TAB)$(OK_COLOR)✓$(NO_COLOR)\n"

$(NAME): $(OBJ)
	@printf "$(OK_COLOR)$(NAME)$(NO_COLOR)"
	@$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
	@printf "$(ALIGN_TAB)$(OK_COLOR)Done ✓$(NO_COLOR)\n"

clean:
	@rm -f $(OBJ)
	@printf "$(SILENT_COLOR)Removed objects$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)Removed $(NAME)$(NO_COLOR)\n"

space:
	@echo

re: fclean space all
