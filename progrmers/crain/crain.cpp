#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    int answer = 0;
    stack <int> s;
    for(auto move_num: moves){
    	for(int i = 0; i < n; i++){
        	if(board[i][move_num-1] != 0){
                if(!s.empty() && s.top() == board[i][move_num - 1]){
                    s.pop();
                    answer +=2;
                }
                else{
                    s.push(board[i][move_num -1]);
                }
                board[i][move_num - 1] = 0;
                break;
            }
        }
        cout << "\n";
    }
    return answer;
}


int main(){

}
