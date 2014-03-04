GTEST_DIR=/home/jkern/src/cpp/googletest-read-only
CXXFLAGS=-g -I$(GTEST_DIR)/include
OBJS = exact.o kmer_node.o
LDFLAGS = -lstdc++ -pthread -lpthread

kmer_node_test: kmer_node.o $(GTEST_DIR)/make/gtest_main.a

exact_test: exact.o $(GTEST_DIR)/make/gtest_main.a

clean:
	rm $(OBJS) exact_test.o exact_test kmer_node_test *~
