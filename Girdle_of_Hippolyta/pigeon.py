# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pigeon_tut.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 15:43:52 by kmira             #+#    #+#              #
#    Updated: 2019/04/26 19:57:44 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# IMPORTANT!!!---------------------------------------------------------------->

# You gmail app acess needs to be changed to allow apps to connect.
# you can find on the following site https://myaccount.google.com/lesssecureapps

# END------------------------------------------------------------------------->

import smtplib
import getpass

user = input('Email: ')
pswd = getpass.getpass('Password: ')
to   = input('To: ')

# Get a SMTP server https://serversmtp.com/smtp-server-address/
# Since we are using gmail we will use the gmail one, default port number is 587
# SMTP_SSL makes a secure connection meaning that the smtp.starttls() function is not needed, nor is the double smtp.ehlo()
with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
	smtp.login(user, pswd)

	subject = 'Message to Local'
	body    = 'Testing a sending message to gmail and stuff'

	msg = f'Subject: {subject}\n\n{body}'

	smtp.sendmail(user, to, msg)

# Thanks to https://www.youtube.com/watch?v=JRCJ6RtE3xU
