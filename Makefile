CC=g++
CFLAGS=--std=c++0x

all: sample tests

tests.o: tests.cpp
	$(CC) $(CFLAGS) -c $^

sample.o: sample.cpp
	$(CC) $(CFLAGS) -c $^

sequence_graph.o: sequence_graph.cpp
	$(CC) $(CFLAGS) -c $^

sample: sample.o sequence_graph.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

tests: tests.o sequence_graph.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) sample tests

clobber: clean
	$(RM) tests.o sample.o sequence_graph.o
