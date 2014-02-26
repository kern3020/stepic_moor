GTEST_DIR=/home/jkern/src/cpp/googletest-read-only
CXXFLAGS=-g -I$(GTEST_DIR)/include
OBJS_TEST = exact.o exact_test.o
LDFLAGS = $(GTEST_DIR)/make/gtest_main.a  -lstdc++ -pthread -lpthread
exact_test: $(OBJS_TEST)

clean:
	rm $(OBJS_TEST) exact_test *~