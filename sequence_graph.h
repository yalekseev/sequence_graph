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

  enum { MAX_NUM_VERTICES = std::numeric_limits<unsigned char>::max() + 1 };

  SequenceGraph();

  /*! \brief Add edges extracted from sequence to graph */
  size_t add_sequence(const std::string & sequence);

  /*! \brief Remove all edges from graph */
  void clear();

  /*! \brief Remove edges extracted from sequence from graph */
  size_t del_sequence(const std::string & sequence);

  /*! \brief Return true if graph built so far has a cycle */
  bool has_cycle() const;

public:
  /*! \brief Add edge to graph. Return true if edge has been added (didn't exist) */
  bool add_edge(size_t src_vertex, size_t dst_vertex);

  /*! \brief Remove edge from graph. Return true if edge has been removed (existed) */
  bool del_edge(size_t src_vertex, size_t dst_vertex);

  mutable std::mutex m_mutex;
  std::vector<AdjacencyList> m_graph;
};

#endif // SEQUENCE_GRAPH_H
