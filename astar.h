//
// Created by Dikshant Gupta on 11/05/22.
//

#ifndef KALMAN_BAYESIAN_FILTERS_ASTAR_H
#define KALMAN_BAYESIAN_FILTERS_ASTAR_H

#endif //KALMAN_BAYESIAN_FILTERS_ASTAR_H

#include <utility>
#include <vector>
#include <string>

struct Node {
    int x;
    int y;
};

class Grid {
public:
    Grid(int width, int height) : width(width), height(height) {
        grid.resize(width * height);
    }

    double& operator[](const Node& node) {
        return grid[node.x * width + node.y];
    }

    int& get_width() {return width;}
    int& get_height() {return height;}

private:
    int width;
    int height;
    std::vector<double> grid;
};

class AStar {
public:
    AStar() = default;
    explicit AStar(std::string  heuristic_) : heuristic(std::move(heuristic_)) {}
    std::vector<Node> find_path(const Node& start, const Node& goal, const Grid& world);

private:
    std::string heuristic = "euclidean";
};
