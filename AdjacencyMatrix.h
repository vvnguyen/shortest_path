#pragma once
#include <vector>
#include <assert.h>

#define CHECK(n,m) assert(m >= 0); assert(n >= 0); assert(m < N); assert(n < N);
template<int N>
struct AdjacencyMatrix
{
	int adj[ N * N ];
	int get_value( int m, int n ) {
		CHECK(n, m)
		return adj[ m * N + n ];
	}

	void set_value( int origin, int destination, int value) {
		CHECK(origin, destination)
		adj [ origin * N + destination ] = value;
	}

	void add_directed_edge(int origin, int destination, int value) {
		set_value( origin, destination, value );
	}

	void add_undirected_edge( int origin, int destination, int value ) {
		set_value( origin, destination, value );
		set_value( destination, origin, value );
	}

	AdjacencyMatrix() {}

	AdjacencyMatrix(std::vector<int>& pairs) : adj{0} {
		int triples = pairs.size() / 3;
		for ( int i = 0; i < triples; ++i ) {
			add_directed_edge( pairs[ 3 * i ], pairs[ 3 * i + 1 ], pairs[ 3 * i + 2 ] );
		}
	}
};
