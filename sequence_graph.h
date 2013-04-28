#ifndef SEQUENCE_GRAPH_H
#define SEQUENCE_GRAPH_H

#include <unordered_set>
#include <limits>
#include <string>
#include <vector>
#include <mutex>

class SequenceGraph {
public:
  typedef std::unordered_set<size_t> AdjacencyList;

  enum { MAX_NUM_VERTICES = std::numeric_limits<unsigned char>::max() };

  SequenceGraph();

  size_t add_sequence(const std::string & sequence);

  void clear();

  size_t del_sequence(const std::string & sequence);

  bool has_cycle() const;

public:
  bool add_edge(size_t src_vertex, size_t dst_vertex);

  bool del_edge(size_t src_vertex, size_t dst_vertex);

  mutable std::mutex m_mutex;
  std::vector<AdjacencyList> m_graph;
};

#endif // SEQUENCE_GRAPH_H
