/* " Output "
. #
.### ### #####
...# #   # #
##.# # ### # ##
 #.# #   #
 #.# ### #####
...#   #     #
.########### #
.........#   #
########.# ####
   # #...#
 # # #.### ### 
 #   #.#   #...
 #####.#####.#.
      .......#.
*/

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>

using namespace std;

const int rows = 15;
const int columns = 15;

enum class Places {
    Path,
    Clear,
    Block,
    Explored
};

//to shuffle the walls of the maze
template<typename RandomIt, typename RandomGenerator>
void swap(RandomIt first, RandomIt last, RandomGenerator& g) {
    for (auto i = last - first - 1; i > 0; --i) {
        uniform_int_distribution<decltype(i)> dist(0, i);
        iter_swap(first + i, first + dist(g));
    }
}

void createmazePuzzleWalls(vector<vector<Places>>& maze) {
    maze.resize(rows, vector<Places>(columns, Places::Block));
}

bool Inside(int x, int y) {
    if (x >= 0 && x < rows && y >= 0 && y < columns) {
        return true;
    } else {
        return false;
    }
}

void printMaze(const vector<vector<Places>>& maze) {
    for (const auto& row : maze) {
        for (const auto& place : row) {
            if (place == Places::Path) {
                cout << ".";
            } else if (place == Places::Clear) {
                cout << " ";
            } else if (place == Places::Block) {
                cout << "#";
            } else if (place == Places::Explored) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void findExplore(vector<vector<Places>>& maze, int startX, int startY) {
    vector<pair<int, int>> stack;
    stack.push_back({startX, startY});

    while (!stack.empty()) {
        int x = stack.back().first;
        int y = stack.back().second;
        stack.pop_back();

        if (!Inside(x, y) || maze[x][y] != Places::Clear)
            continue;

        maze[x][y] = Places::Explored;

        stack.push_back({x - 1, y}); // Up
        stack.push_back({x + 1, y}); // Down
        stack.push_back({x, y - 1}); // Left
        stack.push_back({x, y + 1}); // Right
    }
}

void createmazePuzzle(vector<vector<Places>>& maze, int x, int y, std::mt19937& gen) {
    const int directions[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

    // Randomly shuffle the directions
    vector<pair<int, int>> dirPairs{{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    swap(dirPairs.begin(), dirPairs.end(), gen);

    maze[x][y] = Places::Clear; 

    for (int k = 0; k < 4; ++k) {
        int newX = x + dirPairs[k].first;
        int newY = y + dirPairs[k].second;

        // Check if inside the maze and so is a block
        if (Inside(newX, newY) && maze[newX][newY] == Places::Block) {
            maze[newX][newY] = Places::Clear; 
            maze[x + dirPairs[k].first / 2][y + dirPairs[k].second / 2] = Places::Clear; 
            createmazePuzzle(maze, newX, newY, gen); 
        }
    }
}

bool solution(vector<vector<Places>>& maze, int x, int y) {
    if (!Inside(x, y) || maze[x][y] != Places::Clear)
        return false;
    
    // Bottom right corner then end
    if (x == rows - 1 && y == columns - 1) {
        maze[x][y] = Places::Path;
        return true;
    }

    maze[x][y] = Places::Path;
    bool foundPath = solution(maze, x - 1, y) || solution(maze, x + 1, y) || 
                     solution(maze, x, y - 1) || solution(maze, x, y + 1);

    if (foundPath)
        return true;
    
    maze[x][y] = Places::Explored;
    
    return false;
}

int main() {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    vector<vector<Places>> maze;
    createmazePuzzleWalls(maze);
    maze[0][0] = Places::Clear;

    createmazePuzzle(maze, 0, 0, gen); 
    vector<vector<Places>> mazeCopy = maze;
    findExplore(mazeCopy, 0, 0);

    if (solution(maze, 1, 0)) {
        printMaze(maze);
    } else {
        cout << "The puzzle has no solution." << endl;
    }

    return 0;
}