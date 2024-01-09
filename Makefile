# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanni <asanni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 19:46:24 by asanni            #+#    #+#              #
#    Updated: 2024/01/06 19:48:57 by asanni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

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

SRC = 

#--------------RULES----------------------------#

OBJFILES = $(subst $(SOURCES),$(OBJFOLDER),$(SRC:.c=.o))

all: comp_lib $(OBJFOLDER) $(NAME)

comp_lib:
	@$(MAKE) -sC $(P_LIBFT)

$(OBJFOLDER):
	@mkdir $(OBJFOLDER)

$(NAME): $(OBJFILES)
	$(CC) $(OBJFILES) $(H_LIB) $(LIBFT) $(LINCLUDES) $(CFLAGS) -o $(NAME) -g

$(OBJFOLDER)%.o : $(SOURCES)%.c
	cc $(HEADERS) -c $< -o $@ -g3


#----------------CLEAN--------------------------#

clean:
	rm -f $(OBJFILES) -r $(OBJFOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
