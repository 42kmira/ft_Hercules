# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flood.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 15:10:28 by kmira             #+#    #+#              #
#    Updated: 2019/05/04 12:20:07 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gevent makes pseudo Thread like things
# import gevent

# requests lets us try to request information of a website.
import requests
# This allows multiple processes to be run and so makes concurrent users
import multiprocessing
# This allows us to get the arguements
import sys
import time

try:
	url = sys.argv[1]
	n = int(sys.argv[2])
except Exception:
	n = 25
	url = "https://projects.intra.42.fr/"

average_time = 0
successful_calls = 0
total_bytes = 0

def task(pid):
	response = requests.get(url)
	status_code = response.ok
	amount_of_bytes = len(response.text)
	elapsed_time = float(response.elapsed.total_seconds())
	print("[TASK %s]	Response from %s took %.3fs bytes of response is %d" % (pid + 1, url, elapsed_time, amount_of_bytes))
	return (elapsed_time, amount_of_bytes, status_code)

pool = multiprocessing.Pool(n)
start = time.time()
times, response_length, status_codes = zip(*pool.map(task, [i for i in range(n)]))
end = time.time()

for time in times:
	average_time += time / n

for status_code in status_codes:
	if (status_code == True):
		successful_calls += 1

for response in response_length:
	total_bytes += response
total_bytes = total_bytes / n

print("\nTest took:				%.3f seconds" % (end - start))
print("Average Response Time is		%.4f seconds" % average_time)
print("Amount of Successful calls:		%d / %d" % (successful_calls, n))
print("Percentage: 				%.2f%%" % ((successful_calls/n) * 100))
print("Average Response Length (in bytes)	%.2f" % total_bytes)
print("Response Rate (bytes per second)	%.3f" % (total_bytes / average_time))

# threads = [gevent.spawn(task, i) for i in range(n)]
# start = time.time()
# gevent.joinall(threads)
# end = time.time()
# print("\nTest took %.3f seconds" % (end - start))
# print("Average amount of response time for page %s is %.4f" % (url, average_time))
# print("Amount of successful calls: %d Percentage: %.2f%%" % (successful_calls, (successful_calls/n) * 100))
