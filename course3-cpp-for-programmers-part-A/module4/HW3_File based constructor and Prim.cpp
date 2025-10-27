// Dijkstra Graph Simulation with MST Support
// Description: Graph ADT + Random Graph Generation + Dijkstra's Algorithm + Prim's MST + File-Based Graph Constructor

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <random>
#include <iomanip>
#include <fstream>
#include <tuple>

// Graph class with adjacency list representation
class Graph {
private:
    int V;  // number of vertices
    std::vector<std::vector<std::pair<int, double>>> adjList;  // adjacency list storing (neighbor, weight)

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Constructor to load graph from file (format: V, then lines of i j weight)
    Graph(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile) throw std::runtime_error("Unable to open file");

        infile >> V;
        adjList.resize(V);

        int u, v;
        double weight;
        while (infile >> u >> v >> weight) {
            addEdge(u, v, weight);
        }
    }

    // Add undirected edge between node u and node v with given weight
    void addEdge(int u, int v, double weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);  // undirected graph
    }

    int numVertices() const { return V; }
    const std::vector<std::pair<int, double>>& neighbors(int u) const { return adjList[u]; }

    // Prim's Minimum Spanning Tree algorithm
    void computeMST() const {
        std::vector<bool> inMST(V, false);
        std::vector<double> key(V, std::numeric_limits<double>::infinity());
        std::vector<int> parent(V, -1);

        key[0] = 0.0;
        using P = std::pair<double, int>;  // (key, vertex)
        std::priority_queue<P, std::vector<P>, std::greater<>> pq;
        pq.emplace(0.0, 0);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (const auto& [v, weight] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.emplace(key[v], v);
                    parent[v] = u;
                }
            }
        }

        double totalCost = 0.0;
        std::cout << "\nMinimum Spanning Tree Edges:\n";
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1) {
                std::cout << parent[i] << " - " << i << " (" << key[i] << ")\n";
                totalCost += key[i];
            }
        }
        std::cout << "Total MST Cost: " << totalCost << "\n";
    }
};

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

            if (currentDist > dist[u]) continue;

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

class GraphSimulator {
private:
    int numVertices;
    double density;
    double minDist, maxDist;
    std::mt19937 rng;
    std::uniform_real_distribution<> probDist;
    std::uniform_real_distribution<> weightDist;

public:
    GraphSimulator(int V, double d, double minD, double maxD)
        : numVertices(V), density(d), minDist(minD), maxDist(maxD), rng(std::random_device{}()),
          probDist(0.0, 1.0), weightDist(minD, maxD) {}

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
    const int V = 50;
    const double minDist = 1.0;
    const double maxDist = 10.0;
    std::vector<double> densities = {0.2, 0.4};

    for (double density : densities) {
        GraphSimulator simulator(V, density, minDist, maxDist);
        Graph g = simulator.generate();
        double avg = simulator.averageShortestPath(g);
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "Density: " << (density * 100) << "% -> Average Shortest Path Length: " << avg << "\n";
    }

    // Optional: Read from file and compute MST
    try {
        Graph gFromFile("graph_input.txt");
        gFromFile.computeMST();
    } catch (const std::exception& e) {
        std::cerr << "Error loading graph from file: " << e.what() << "\n";
    }

    return 0;
}
