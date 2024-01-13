# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanni <asanni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 17:27:11 by asanni            #+#    #+#              #
#    Updated: 2024/01/12 20:16:14 by asanni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SVR_NAME= server 
CLT_NAME = client
#--------------FLAGS----------------------------#

CFLAGS = -Wall -Werror -Wextra -g3

#--------------PATHS----------------------------#

OBJFOLDER = objs/
SOURCES = sources/

P_LIBFT = libft/
LIBFT = $(P_LIBFT)libft.a

H_LIB = -I include/
LINCLUDES = -L./libft -lft

#--------------FILES----------------------------#

SRC_SVR = sources/server.c
SRC_CLT = sources/client.c

#--------------RULES----------------------------#

OBJ_SVR = $(subst $(SOURCES),$(OBJFOLDER),$(SRC_SVR:.c=.o))
OBJ_CLT = $(subst $(SOURCES),$(OBJFOLDER),$(SRC_CLT:.c=.o))

all: comp_lib $(OBJFOLDER) $(NAME)

$(NAME): $(SVR_NAME) $(CLT_NAME)

comp_lib:
	@$(MAKE) -sC $(P_LIBFT)

$(OBJFOLDER):
	@mkdir $(OBJFOLDER)

$(SVR_NAME): $(OBJ_SVR)
	$(CC) $(OBJ_SVR) $(H_LIB) $(LIBFT) $(LINCLUDES) $(CFLAGS) -o $(SVR_NAME) -g

$(CLT_NAME): $(OBJ_CLT)
	$(CC) $(OBJ_CLT) $(H_LIB) $(LIBFT) $(LINCLUDES) $(CFLAGS) -o $(CLT_NAME) -g

$(OBJFOLDER)%.o : $(SOURCES)%.c
	cc $(HEADERS) -c $< -o $@ -g3


#----------------CLEAN--------------------------#

clean:
	rm -f $(OBJFILES) -r $(OBJFOLDER)

fclean: clean
	rm -f $(NAME) $(SVR_NAME) $(CLT_NAME)

re: fclean all
.PHONY: all clean fclean re
