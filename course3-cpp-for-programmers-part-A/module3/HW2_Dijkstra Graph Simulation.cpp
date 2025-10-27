// Dijkstra Graph Simulation
// Description: Graph ADT + Random Graph Generation + Dijkstra's Algorithm + Average Path Length
// Uses adjacency list representation for efficient memory and faster traversal on sparse graphs.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <random>
#include <iomanip>

// Graph class with adjacency list representation
class Graph {
private:
    int V;  // number of vertices
    std::vector<std::vector<std::pair<int, double>>> adjList;  // adjacency list storing (neighbor, weight)

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Add undirected edge between node u and node v with given weight
    void addEdge(int u, int v, double weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);  // undirected graph
    }

    // Return number of vertices
    int numVertices() const { return V; }

    // Get all neighbors of a given node
    const std::vector<std::pair<int, double>>& neighbors(int u) const { return adjList[u]; }
};

// Dijkstra's algorithm to compute shortest paths from a source node
class Dijkstra {
public:
    static std::vector<double> shortestPath(const Graph& g, int source) {
        int V = g.numVertices();
        std::vector<double> dist(V, std::numeric_limits<double>::infinity());
        dist[source] = 0.0;

        using P = std::pair<double, int>;  // (distance, node)
        std::priority_queue<P, std::vector<P>, std::greater<>> pq;
        pq.emplace(0.0, source);

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist > dist[u]) continue;  // Skip if already found better path

            for (const auto& [v, weight] : g.neighbors(u)) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }
};

// GraphSimulator class generates random graphs and evaluates average shortest path length
class GraphSimulator {
private:
    int numVertices;
    double density;
    double minDist, maxDist;
    std::mt19937 rng;
    std::uniform_real_distribution<> probDist;  // for density-based edge generation
    std::uniform_real_distribution<> weightDist;  // for random edge weights

public:
    GraphSimulator(int V, double d, double minD, double maxD)
        : numVertices(V), density(d), minDist(minD), maxDist(maxD), rng(std::random_device{}()),
          probDist(0.0, 1.0), weightDist(minD, maxD) {}

    // Generate a random undirected graph with given density and weight range
    Graph generate() {
        Graph g(numVertices);
        for (int i = 0; i < numVertices; ++i) {
            for (int j = i + 1; j < numVertices; ++j) {
                if (probDist(rng) < density) {
                    double weight = weightDist(rng);
                    g.addEdge(i, j, weight);
                }
            }
        }
        return g;
    }

    // Compute average shortest path from source to all reachable nodes
    double averageShortestPath(const Graph& g, int source = 0) {
        auto distances = Dijkstra::shortestPath(g, source);
        double sum = 0.0;
        int count = 0;
        for (int i = 0; i < distances.size(); ++i) {
            if (i != source && distances[i] < std::numeric_limits<double>::infinity()) {
                sum += distances[i];
                ++count;
            }
        }
        return (count == 0) ? 0.0 : sum / count;
    }
};

int main() {
    const int V = 50;  // number of nodes in graph
    const double minDist = 1.0;  // minimum distance for edge weights
    const double maxDist = 10.0; // maximum distance for edge weights
    std::vector<double> densities = {0.2, 0.4};  // test densities

    for (double density : densities) {
        GraphSimulator simulator(V, density, minDist, maxDist);
        Graph g = simulator.generate();
        double avg = simulator.averageShortestPath(g);

        std::cout << std::fixed << std::setprecision(3);
        std::cout << "Density: " << (density * 100) << "% -> Average Shortest Path Length: " << avg << "\n";
    }

    return 0;
}
