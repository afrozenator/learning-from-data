CC=g++
CFLAGS=-std=c++0x -I.

testing_main.out: testing_main.cc random_points.o line.o perceptron_learning_algorithm.o
	$(CC) random_points.o line.o perceptron_learning_algorithm.o testing_main.cc -o testing_main.out $(CFLAGS)

perceptron_learning_algorithm.o: perceptron_learning_algorithm.cc perceptron_learning_algorithm.h line.o random_points.o
	$(CC) -c perceptron_learning_algorithm.cc $(CFLAGS)

line.o: line.cc line.h random_points.o
	$(CC) -c line.cc $(CFLAGS)

random_points.o: random_points.cc random_points.h
	$(CC) -c random_points.cc $(CFLAGS)

clean:
	rm -rf *.o *.out *.gch
