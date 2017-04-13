#pragma once
#include <climits>
#include "AdjacencyMatrix.h"

template<int N>
void bellman_ford_shortest_path( struct AdjacencyMatrix<N> adj_m, int source, long long int (&d)[N]) {

	//long long int d[ N ];
	int pi[ N ] = { 0 };

	//initialize single source
	for ( int i = 0; i < N; ++i ) {
		d[ i ] = INT_MAX;
	}

	d[ source ] = 0;

	long long int sum = 0;
	for ( int vertice = 0; vertice < N; ++vertice ) {
		for ( int destination = 0; destination < N; ++destination ) {
			sum = d[ vertice ] + adj_m.get_value( destination, vertice );
			if ( sum < d[ destination ] ) {
				d[ destination ] = sum;
				pi[ destination ] = vertice;
			}
		}
	}
}