The SequenceGraph is a class that allows to build a graph on string sequences of
the form "eakl", where sequence "eakl" embodies the following sequence relations:

* 'a' follows follows 'e'.
* 'k' follows 'a' and 'e'.
* 'l' follows 'k', 'a' and 'e'.

Each relation (like 'a' follows 'e' in the above) is represented by an edge in the
graph.

The SequenceGraph class also allows to check if the graph built so far is acyclic.
