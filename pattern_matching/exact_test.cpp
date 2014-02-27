#include "gtest/gtest.h"
#include "exact.h"

#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring> 
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>


TEST(ExactTest, SimpleCommonCase) {
  list<int> exp;
  exp.push_front(9);
  EXPECT_EQ(exp, exact_match("BARB", "FOOBUBBABBARBIZBAZ"));
}

TEST(ExactTest, SimpleSeqCase) {
  string filename("test_data/foo.fasta");
  ifstream fasta_file(filename.c_str());
  int seq_size = 512;
  int line_size = 128;
  char *buf = new char(line_size); 
  string seq;
  
  if ( !fasta_file) {
    FAIL() << "can't open input file \"" << filename << "\"";
  }

  // ignore - header which is the first line of the fasta file.
  char c;
  do {
    fasta_file.get(c);
  } while (fasta_file.eof() || c != '\n');

  // begining of range to read
  int beg_pos = fasta_file.tellg(); 

  // end of range
  fasta_file.seekg(0, std::ios::end); 
  int end_pos = fasta_file.tellg();

  // resize
  int s = end_pos - beg_pos;
  seq.resize(s);

  //reset to begining of range
  fasta_file.seekg(beg_pos);
  fasta_file.read(&seq[0], s);
  
  seq.erase( std::remove_if( seq.begin(), seq.end(), ::isspace ), seq.end() );

  list<int> exp;
  exp.push_back(4);
  exp.push_back(166);
  exp.push_back(222);
  exp.push_back(334);
  exp.push_back(344);
  
  EXPECT_EQ(exp, exact_match("GTA", seq)); // CAATA
}

