Main:
	@g++ -std=c++11 -Wall -g main.cpp graph.cpp algorithms.cpp queue.cpp priority_queue.cpp union_find.cpp -o Main && ./Main

test:
	@g++ -std=c++11 -Wall -g tests.cpp graph.cpp algorithms.cpp queue.cpp priority_queue.cpp union_find.cpp -o test && ./test

valgrind:
	@valgrind --leak-check=full ./Main

clean:
	@rm -f Main test