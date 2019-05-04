# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    floodtest.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 12:45:15 by kmira             #+#    #+#              #
#    Updated: 2019/05/04 12:17:05 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests
import time
import gevent

url = "https://github.com"

averge_time = 0
n = 10
i = 0
toggle = 0

def test(url):
	global averge_time
	start = time.time()
	status_code = requests.head(url).status_code
	end = time.time()
	elapsed_time = round(end - start, 2)
	print(str(elapsed_time) + " for " + str(status_code))
	averge_time = averge_time + (elapsed_time / n)
	global i
	global toggle
	i = i + 1
	if (i == 5):
		print("Going to sleep")
		time.sleep(10)
		print("Finished!")
		toggle = 1
	if (toggle == 0):
		print("Thread power")


print(str(averge_time))

threads = [gevent.spawn(test, url) for i in range(n)]
gevent.joinall(threads)

print(str(round(averge_time, 2)))
# print("Website " + url + " took " + str(round(averge_time, 2)) + " to send request status: " + str(status_code))
