#include <iostream>

#include "sequence_graph.h"

int main() {
  SequenceGraph sequence_graph;

  std::cout << "Creating graph with a cycle" << std::endl;

  std::cout << "Adding sequence 'abc'" << std::endl;
  sequence_graph.add_sequence("abc");

  std::cout << "Adding sequence 'cde'" << std::endl;
  sequence_graph.add_sequence("cde");

  std::cout << "Adding sequence 'efa'" << std::endl;
  sequence_graph.add_sequence("efa");

  if (sequence_graph.has_cycle()) {
    std::cout << "PASSED: The resulting graph does indeed have a cycle!" << std::endl;
  } else {
    std::cout << "FAILED: The resulting graph doesn't have a cycle!" << std::endl;
  }

  return 0;
}
