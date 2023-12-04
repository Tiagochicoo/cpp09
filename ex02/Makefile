PROG 		= PmergeMe
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address
SRCS		= ./srcs/*.cpp
INC			= ./includes
3000ARG		= $$(ruby -e 'puts (1..10000).to_a.shuffle.first(3000).join(" ")')
10000ARG	= $$(ruby -e 'puts (1..20000).to_a.shuffle.first(10000).join(" ")')
100000ARG	= $$(ruby -e 'puts (1..200000).to_a.shuffle.first(100000).join(" ")')
1000000ARG	= $$(ruby -e 'puts (1..2000000).to_a.shuffle.first(1000000).join(" ")')

all : $(PROG)

$(PROG) : $(SRCS) $(INC)
	@$(CXX) $(CXXFLAGS) $(SRCS) -I$(INC) -o $(PROG)
	@printf "\e[38;5;46m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[38;5;46m█▓▒░	   Compiled PmergeMe   	    ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m ╚════════════════════════════════════╝\e[0m\n"

clean :
	@rm -rf $(PROG) *.dSYM *.out
	@printf "\e[31;5;200m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[31;5;200m░▒▓█         Clean complete         █▓▒░\e[0m\n"
	@printf "\e[31;5;200m ╚════════════════════════════════════╝\e[0m\n"

3000 :
	@printf "\e[34m█▓▒░        3000 Numbers     ░▒▓█ \e[0m\n";
	@$(CXX) $(CXXFLAGS) $(SRCS) -I$(INC) -o $(PROG)
	@./PmergeMe $(3000ARG)

10000 : all
	@printf "\e[34m█▓▒░        10k Numbers     ░▒▓█ \e[0m\n";
	@$(CXX) $(CXXFLAGS) $(SRCS) -I$(INC) -o $(PROG)
	@./PmergeMe $(10000ARG)

100000 : all
	@printf "\e[34m█▓▒░        100k Numbers     ░▒▓█ \e[0m\n";
	@$(CXX) $(CXXFLAGS) $(SRCS) -I$(INC) -o $(PROG)
	@./PmergeMe $(10000ARG)

1000000 : all
	@printf "\e[34m█▓▒░        1M Numbers     ░▒▓█ \e[0m\n";
	@$(CXX) $(CXXFLAGS) $(SRCS) -I$(INC) -o $(PROG)
	@./PmergeMe $(100000ARG)

fclean : clean
	@rm -rf $(PROG)

re : fclean all