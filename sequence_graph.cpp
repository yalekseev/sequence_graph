#include <unordered_map>
#include <cassert>
#include <string>
#include <stack>
#include <mutex>

#include "sequence_graph.h"

SequenceGraph::SequenceGraph() : m_graph(MAX_NUM_VERTICES) { }

size_t SequenceGraph::add_sequence(const std::string & sequence) {
  size_t added_edges_count = 0;

  size_t src_vertex, dst_vertex;
  for (auto it = sequence.begin(); it != sequence.end(); ++it) {
    if (it == sequence.begin()) {
      dst_vertex = *it;
      continue;
    }

    src_vertex = dst_vertex;
    dst_vertex = *it;

    if (add_edge(src_vertex, dst_vertex)) {
      ++added_edges_count;
    }
  }

  return added_edges_count;
}

void SequenceGraph::clear() {
  std::lock_guard<std::mutex> lock(m_mutex);

  m_graph.clear();
  m_graph.resize(MAX_NUM_VERTICES);
}

size_t SequenceGraph::del_sequence(const std::string & sequence) {
  size_t deleted_edges_count = 0;

  size_t src_vertex, dst_vertex;
  for (auto it = sequence.begin(); it != sequence.end(); ++it) {
    if (it == sequence.begin()) {
      dst_vertex = *it;
      continue;
    }

    src_vertex = dst_vertex;
    dst_vertex = *it;

    if (del_edge(src_vertex, dst_vertex)) {
      ++deleted_edges_count;
    }
  }

  return deleted_edges_count;
}

/*! \brief Return true if graph has a cycle, otherwise return false. */
bool SequenceGraph::has_cycle() const {
  std::lock_guard<std::mutex> lock(m_mutex);

  enum VertexTraversalState { NEW = 0, SEEN = 1, PROCESSED = 2 };

  std::unordered_map<size_t, VertexTraversalState> vertex_state(m_graph.size());

  // Graph has a loop when we discover a SEEN vertex during DFS traversal
  for (size_t start_vertex = 0; start_vertex < m_graph.size(); ++start_vertex) {
    if (vertex_state[start_vertex] != NEW) {
      assert(vertex_state[start_vertex] == PROCESSED);
      continue;
    }

    std::stack<size_t> vertex_traversal_stack;
    vertex_traversal_stack.push(start_vertex);

    while (!vertex_traversal_stack.empty()) {
      // Get next vertex to traverse, but don't remove it from stack yet
      size_t vertex = vertex_traversal_stack.top();

      vertex_state[vertex] = SEEN;

      bool found_new_adjacent_vertex = false;
      for (size_t adjacent_vertex : m_graph[vertex]) {
        if (vertex_state[adjacent_vertex] == NEW) {
          vertex_traversal_stack.push(adjacent_vertex);
          found_new_adjacent_vertex = true;
        } else if (vertex_state[adjacent_vertex] == SEEN) {
          return true;
        }
      }

      if (found_new_adjacent_vertex) {
        // Process new adjacent vertex first
        continue;
      }

      // All adjacent vertices have been processed so mark
      // vertex as processed and remove it from traversal stack
      vertex_state[vertex] = PROCESSED;
      vertex_traversal_stack.pop();
    }
  }

  return false;
}

bool SequenceGraph::add_edge(size_t src_vertex, size_t dst_vertex) {
  std::lock_guard<std::mutex> lock(m_mutex);

  auto res_pair = m_graph[src_vertex].insert(dst_vertex);
  if (res_pair.second) {
    return true;
  }

  return false;
}

bool SequenceGraph::del_edge(size_t src_vertex, size_t dst_vertex) {
  std::lock_guard<std::mutex> lock(m_mutex);

  if (m_graph[src_vertex].erase(dst_vertex) != 0) {
    return true;
  }

  return false;
}
