GTEST_DIR=/home/jkern/src/cpp/googletest-read-only
WARNINGS= -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
CXXFLAGS=-O2 -gdwarf-2 -std=c++11 -I$(GTEST_DIR)/include
OBJS = kmer_node.o bk_tree.o freq_partial.o
TEST_EXE = kmer_node_test bk_tree_test freq_partial_test
LDFLAGS = -lstdc++ -pthread -lpthread

.PHONY: test_all
test_all: $(TEST_EXE)
	./kmer_node_test
	./bk_tree_test
	./freq_partial_test

kmer_node_test: kmer_node.o $(GTEST_DIR)/make/gtest_main.a

bk_tree_test: kmer_node.o bk_tree.o $(GTEST_DIR)/make/gtest_main.a

freq_partial_test: $(OBJS) $(GTEST_DIR)/make/gtest_main.a

exact_test: exact.o $(GTEST_DIR)/make/gtest_main.a

.PHONY: clean
clean:
	rm $(OBJS) $(TEST_EXE) *~ 2> /dev/null
