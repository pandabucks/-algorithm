#include <iostream>
#include<map>
#include<vector>

using namespace std;

typedef pair<int,int> abs_pos;

const bool UNFREE = true;
const bool FREE = false;

const int N = 8;
bool row[N], col[N], pos[2*N - 1], neg[2*N - 1];
vector<abs_pos> all_abs_pos;

// print
void PrintToStdOut(){
    bool Board[N][N];
    for (int i =0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Board[i][j] = FREE;
        }
    }

    for (int i = 0; i < all_abs_pos.size(); i++) {
        Board[all_abs_pos[i].first][all_abs_pos[i].second] = UNFREE;
    }
    // print board
    for (int i =0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Board[i][j]) {
                cout << "Q";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
    exit(0);
}

void Set(int x, int y) {
    col[x] = row[y] = pos[x + y] = neg[x - y + N - 1] = UNFREE;
    all_abs_pos.push_back(abs_pos(x, y));
}

void UnSet(int x, int y) {
    col[x] = row[y] = pos[x + y] = neg[x - y + N - 1] = FREE;
    all_abs_pos.pop_back();
}
bool Check(int x, int y) {
    return (col[x] || row[y] || pos[x + y] || neg[x - y + N - 1] );
}

// do recursive
void Rec(int y) {
    if (y >= N) {
        PrintToStdOut();
    }
    if (row[y]) {
        Rec(y + 1);
    } else {
        for(int x = 0; x < N; x++) {
            if (!Check(x, y)) {
                Set(x, y);
                Rec(y + 1);
                UnSet(x, y);
            }
        }
    }
}

int main(){
  int K;
  cin >> K;
  for(int i = 0; i < K; i++) {
    int X, Y;
    cin >> X >> Y;
    Set(X, Y);
  }
  Rec(0);
  return 0;
}
