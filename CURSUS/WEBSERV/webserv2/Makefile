########################################
### Makefile for the webserv project ###
########################################

NAME = webserv

SRCS = srcs/main.cpp \
       srcs/Server.cpp \
       srcs/Config.cpp \
       srcs/Request.cpp \
       srcs/Response.cpp \
       srcs/CGI.cpp

OBJS = $(SRCS:srcs/%.cpp=obj/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -D_GLIBCXX_USE_CXX11_ABI=0

INC = -I include

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)... ⏳"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully! 🎉"

obj/%.o: srcs/%.cpp
	@if [ ! -d obj ]; then mkdir -p obj; echo "Creating object directory obj... 🗂️"; echo "Object directory created. ✅"; fi
	@echo "Compiling $< into $@... 📄"
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	@echo "$< compiled into $@ successfully. ✅"

clean:
	@echo "Cleaning object files... 🧹"
	rm -rf obj
	@echo "Object files cleaned! ✅"

fclean: clean
	@echo "Cleaning $(NAME)... 🧹"
	rm -f $(NAME)
	@echo "$(NAME) cleaned! ✅"

re: fclean all

.PHONY: all clean fclean re