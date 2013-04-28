#include <iostream>

#include "sequence_graph.h"

int main() {
  SequenceGraph sequence_graph;

  sequence_graph.add_sequence("ac");
  sequence_graph.add_sequence("bc");
  sequence_graph.add_sequence("ab");

  if (!sequence_graph.has_cycle()) {
    std::cout << "TEST 1: PASSED" << std::endl;
  } else {
    std::cout << "TEST 1: FAILED" << std::endl;
  }

  sequence_graph.clear();

  sequence_graph.add_sequence("ab");
  sequence_graph.add_sequence("ba");

  if (sequence_graph.has_cycle()) {
    std::cout << "TEST 2: PASSED" << std::endl;
  } else {
    std::cout << "TEST 2: FAILED" << std::endl;
  }

  sequence_graph.clear();

  sequence_graph.add_sequence("ab");
  sequence_graph.add_sequence("bc");
  sequence_graph.add_sequence("ca");

  if (sequence_graph.has_cycle()) {
    std::cout << "TEST 3: PASSED" << std::endl;
  } else {
    std::cout << "TEST 3: FAILED" << std::endl;
  }

  sequence_graph.clear();

  sequence_graph.add_sequence("ab");
  sequence_graph.add_sequence("ac");
  sequence_graph.add_sequence("bc");
  sequence_graph.add_sequence("ba");

  if (sequence_graph.has_cycle()) {
    std::cout << "TEST 4: PASSED" << std::endl;
  } else {
    std::cout << "TEST 4: FAILED" << std::endl;
  }

  sequence_graph.clear();

  sequence_graph.add_sequence("aa");

  if (sequence_graph.has_cycle()) {
    std::cout << "TEST 5: PASSED" << std::endl;
  } else {
    std::cout << "TEST 5: FAILED" << std::endl;
  }

  sequence_graph.clear();

  sequence_graph.add_sequence("abdc");
  sequence_graph.add_sequence("abc");
  sequence_graph.add_sequence("ac");
  sequence_graph.add_sequence("ad");

  if (!sequence_graph.has_cycle()) {
    std::cout << "TEST 6: PASSED" << std::endl;
  } else {
    std::cout << "TEST 6: FAILED" << std::endl;
  }

  return 0;
}
