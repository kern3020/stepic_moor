GTEST_DIR=/home/jkern/src/cpp/googletest-read-only
CXXFLAGS=-g -gdwarf-2 -std=c++11 -I$(GTEST_DIR)/include
OBJS = exact.o kmer_node.o bk_tree.o
LDFLAGS = -lstdc++ -pthread -lpthread

.PHONY: test_all
test_all: bk_tree_test kmer_node_test
	./kmer_node_test
	./bk_tree_test

bk_tree_test: kmer_node.o bk_tree.o $(GTEST_DIR)/make/gtest_main.a

kmer_node_test: kmer_node.o $(GTEST_DIR)/make/gtest_main.a

exact_test: exact.o $(GTEST_DIR)/make/gtest_main.a

.PHONY: clean
clean:
	rm $(OBJS) exact_test bk_node_test kmer_node_test *~ 2> /dev/null
