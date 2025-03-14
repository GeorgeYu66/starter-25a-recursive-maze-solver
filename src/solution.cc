#include "solution.hpp"

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {
  std::vector<std::pair<unsigned int, unsigned int>> path;
  std::vector<std::vector<bool>> visited = std::vector<std::vector<bool>>(
      maze.size(), std::vector<bool>(maze[0].size(), false));
  SolveMazeRecursive(maze, start_x, start_y, path, visited);
  return path;
}

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {
  // assume this is on the path
  path.push_back(std::make_pair(x, y));
  // base case
  if (maze[x][y] == 'X') {
    return true;
  }
  if (maze[x][y] == '#') {
    path.pop_back();
    visited[x][y] = false;
    return false;
  }
  if (visited[x][y]) {
    path.pop_back();
    return false;
  }
  visited[x][y] = true;
  if (!(x + 1 == maze.size())) {
    if (SolveMazeRecursive(maze, x + 1, y, path, visited)) {
      return true;
    }
  }
  if (!(x == 0)) {
    if (SolveMazeRecursive(maze, x - 1, y, path, visited)) {
      return true;
    }
  }
  if (!(y + 1 == maze[0].size())) {
    if (SolveMazeRecursive(maze, x, y + 1, path, visited)) {
      return true;
    }
  }
  if (!(y == 0)) {
    if (SolveMazeRecursive(maze, x, y - 1, path, visited)) {
      return true;
    }
  }
  path.pop_back();
  visited[x][y] = false;
  return false;
}
