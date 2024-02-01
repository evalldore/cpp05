NAME			:= form
CPPFLAGS		:= -g -Wall -Wextra -Werror
STD				:= -std=c++98
SRCS			:= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
BINDIR			:= bin/
OBJS			:= $(addprefix $(BINDIR), $(SRCS:.cpp=.o))
RM				:= rm -f
CC				:= c++

all : $(NAME)

$(BINDIR)%.o : $(SRCDIR)%.cpp
	@$(CC) -c $(CPPFLAGS) $(STD) -o $@ $^

$(NAME) : $(BINDIR) $(OBJS)
	@echo $(NAME): Compiling!
	@$(CC) $(CPPFLAGS) $(STD) -o $(NAME) $(OBJS)

$(BINDIR) :
	@mkdir $(BINDIR)

clean:
	@echo $(NAME): Deleting binaries.
	@rm -r $(BINDIR)

fclean: clean
	@echo $(NAME): Deleting program.
	@rm -f $(NAME)

re : fclean all