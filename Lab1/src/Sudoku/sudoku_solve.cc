#include <assert.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include "sudoku.h"
using namespace std;

const int puzzle_num = 1024;
const int thread_max_num = 100;

thread th[thread_max_num];
char puzzle[128];

int thread_num = 1;
int puzzle_buf[puzzle_num][N];

void solve(int start, int end) {
  for (int i = start; i < end; i++)
    solve_sudoku_dancing_links(puzzle_buf[i]);
}
void init() { thread_num = thread::hardware_concurrency(); }
void trans(char in[N], int *target) {
  for (int i = 0; i < N; i++) {
    target[i] = in[i] - 48;
  }
}
void file_handle(string file_name) {
  ifstream input_file(file_name, ios::in);
  bool end_of_file = false;
  while (!end_of_file) {
    // 按块来取数据
    int line_count = 0;
    while (line_count < puzzle_num) {
      if (input_file.eof()) {
        end_of_file = true;
        break;
      }
      input_file.getline(puzzle, N + 1);
      if (strlen(puzzle) >= N) {
        trans(puzzle, puzzle_buf[line_count]);
        line_count++;
      }
    };

    // 将数据分块给线程处理
    int start = 0, step = (line_count + 1 + thread_num) / thread_num;
    for (int i = 0; i < thread_num; i++, start += step) {
      th[i] = thread(solve, start,
                     (start + step >= line_count) ? line_count : start + step);
    }
    for (int i = 0; i < thread_num; i++)
      th[i].join();

    // 输出数据到文件中
    for (int i = 0; i < line_count; i++) {
      for (int j = 0; j < N; j++)
        cout << puzzle_buf[i][j];
      cout << endl;
    }
  }
  input_file.close();
}
int main(int argc, char *argv[]) {
  init();
  string file_name;
  while (getline(cin, file_name)) {
    file_handle(file_name);
  }
  return 0;
}
