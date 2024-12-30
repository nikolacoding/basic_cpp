#include <iostream>
#include "Graph.h"

int main()
{
	DirectedGraph<std::string, std::string> graph;

	graph.add("0", "A");
	graph.add("1", "B");
	graph.connect("0", "1");

	auto printFunction = [](const std::string& str) {std::cout << str << ' '; };

	graph.getVertex("0").traverseBfs(printFunction);
	std::cout << std::endl;

	graph.getVertex("1").traverseBfs(printFunction);
	std::cout << std::endl;

	graph.connect("1", "0");

	graph.getVertex("1").traverseBfs(printFunction);
	std::cout << std::endl;

	graph.add("2", "C");
	graph.connect("0", "2");
	graph.connect("1", "2");
	graph.connect("2", "0");
	
	graph.getVertex("2").traverseBfs(printFunction);
	std::cout << std::endl;
}