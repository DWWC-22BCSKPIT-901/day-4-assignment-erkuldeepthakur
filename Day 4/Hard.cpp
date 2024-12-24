#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;


string removeGroups(string board) {
    int i = 0;
    while (i < board.size()) {
        int j = i;
        while (j < board.size() && board[j] == board[i]) {
            j++;
        }
        if (j - i >= 3) {
            
            board = board.substr(0, i) + board.substr(j);
            i = 0; 
        } else {
            i = j; 
        }
    }
    return board;
}

class ZumaGame {
public:
    int findMinStep(string board, string hand) {
        // Memoization map
        unordered_map<string, int> memo;
        int result = dfs(board, hand, memo);
        return result == INT_MAX ? -1 : result;
    }

private:
    int dfs(string board, string hand, unordered_map<string, int>& memo) {
    
        if (board.empty()) {
            return 0;
        }

    
        if (hand.empty()) {
            return INT_MAX;
        }

    
        string state = board + "#" + hand;
        if (memo.find(state) != memo.end()) {
            return memo[state];
        }

        int minSteps = INT_MAX;

    
        for (int i = 0; i < hand.size(); ++i) {
            for (int j = 0; j <= board.size(); ++j) {
    
                string newBoard = board.substr(0, j) + hand[i] + board.substr(j);
    
                newBoard = removeGroups(newBoard);
    
                string newHand = hand.substr(0, i) + hand.substr(i + 1);
                minSteps = min(minSteps, 1 + dfs(newBoard, newHand, memo));
            }
        }

    
        memo[state] = minSteps;
        return minSteps;
    }
};

int main() {
    ZumaGame game;

    
    string board1 = "WRRBBW", hand1 = "RB";
    cout << game.findMinStep(board1, hand1) << endl; 

    string board2 = "WWRRBBWW", hand2 = "WRBRW";
    cout << game.findMinStep(board2, hand2) << endl; 

    string board3 = "G", hand3 = "GGGGG";
    cout << game.findMinStep(board3, hand3) << endl; 

    return 0;
}
