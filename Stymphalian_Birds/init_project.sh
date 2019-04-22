# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init_project.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 12:20:39 by kmira             #+#    #+#              #
#    Updated: 2019/04/05 17:17:07 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------USAGE ERROR----------------------------------------#
if [[ $# == 0 ]] ; then
	echo "Usage error: Did you mean: .init_project.sh -h"
	exit 1;
fi

#----------------------------HELP----------------------------------------------#
if [[ $# == 1 && ("$1" == "-h" || "$1" == "--help") ]] ; then
	echo "Welcome to the help section of the init_project"
	echo ""
	echo ".init_project.sh -h [language] -A [name] -l [+]"
	echo ""
	echo "The goal of this script is to make your life a bit easier by automating"
	echo "some of the repetitive settings you would usually do when starting a"
	echo "project."
	echo ""
	echo "The following options are available:"
	echo ""
	echo "        -h, --help"
	echo "                Displays this page, showing a help section."
	echo ""
	echo "        -l [language]"
	echo "                Specify which language you want the project to start in."
	echo ""
	echo "        -A [name]"
	echo "                Specify whether to include a Author file. Takes the arguement of name"
	echo "                and creates a file with that string and a newline at the end."
	echo ""
	echo "        -l"
	echo "                Specify whether to include libft."
	exit 1;
fi


#----------------------------C------------------------------------------------#
if [[ $1 == "C" ]] ; then
	echo "Making your C library things"

	if [[ $# > 1 && $2 == "-A" ]] ; then
		touch author
		echo "$3" > ./author
	fi

	if [[ ($# > 1 && $2 == "-l") || ($# > 3 && $4 == "-l") ]] ; then
		mkdir includes/ scrs/
		echo "Fetch the right files from an offsource directory and do a cp command here. But eh..."
	fi

#----------------------------MAKEFILE----------------------------------------#
	if [[ ! -f makefile ]] ; then
		touch makefile
		echo "NAME	= [NAME]" >> makefile
		echo "FLAGS	= -Wall -Werror -Wextra -c" >> makefile
		echo "" >> makefile
		echo ".PHONY: clean fclean all re" >> makefile
		echo "" >> makefile
		echo "all: \$(NAME)" >> makefile
		echo "" >> makefile
		echo "clean:" >> makefile
		echo "" >> makefile
		echo "fclean: clean" >> makefile
		echo "" >> makefile
		echo "re: fclean all" >> makefile
	fi

	echo "Creating a .gitignore file."
	touch .gitignore
	echo ":catclap: :catclap: :catclap:" >> .gitignore
	echo "No one said it had to be functional right?"
fi

#----------------------------RUBY---------------------------------------------#
if [[ $1 == "Ruby" ]] ; then
	echo "Making Ruby library things"
	echo "Nothing to be made...."
	echo "Finished however!"
fi

#----------------------------PYTHON--------------------------------------------#
if [[ $1 == "Python" ]] ; then
	echo "Making Python library things"
	echo "Nothing to be made...."
	echo "Finished however!"
fi

#----------------------------JAVASCRIPT----------------------------------------#
if [[ $1 == "Javascript" ]] ; then
	echo "Making Javascript library things"
	echo "Nothing to be made...."
	echo "Finished however!"
fi

echo "Finsihed! 🦄"
