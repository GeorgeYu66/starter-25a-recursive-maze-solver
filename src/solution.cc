#include "solution.hpp"

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {
  std::vector<std::pair<unsigned int, unsigned int>> path;
  std::vector<std::vector<bool>> visited = std::vector<std::vector<bool>>(
      maze.size(), std::vector<bool>(maze[0].size(), false));
  unsigned int i = start_x;
  unsigned int j = start_y;
  if (SolveMazeRecursive(maze, i, j, path, visited)) {
    path.push_back(std::make_pair(i, j));
  };
  if (maze[i][j] == 'X') {
    return path;
  }
}

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {
  return false;
}