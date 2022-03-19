#include <assert.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>

#include "sudoku.h"
#include "threadpool.h"
using namespace std;

// ios和stdio的同步是否打开
#define SYNC 0

ThreadPool thread_pool;
int thread_num = 1;
char one_puzzle[128];
const int puzzle_buf_num = 10240;
int puzzle_buf[puzzle_buf_num][N];

// 解数独
int solve(int start, int end) {
  for (int i = start; i < end; i++)
    solve_sudoku_dancing_links(puzzle_buf[i]);
  return 0;
}

void print(int line_num) {
  for (int i = 0; i < line_num; i++) {
    for (int j = 0; j < N; j++)
      putchar('0' + puzzle_buf[i][j]);
    putchar('\n');
  }
}

void file_process(string file_name) {
  ifstream input_file(file_name, ios::in);
  vector<future<int>> results;
  while (!input_file.eof()) {
    // 取数据
    int line_num = 0;
    while (!input_file.eof() && line_num < puzzle_buf_num) {
      input_file.getline(one_puzzle, N + 1);
      if (strlen(one_puzzle) >= N) {
        for (int i = 0; i < N; i++)
          puzzle_buf[line_num][i] = one_puzzle[i] - 48;
        line_num++;
      }
    };

    // 分数据
    int start = 0, end = 0, len = (line_num + thread_num) / thread_num;
    for (int i = 0; i < thread_num; i++) {
      end = (start + len >= line_num) ? line_num : start + len;
      results.emplace_back(thread_pool.enqueue(solve, start, end));
      start += len;
    }
    for (auto &&result : results)
      result.wait();

    // 输出数据
    print(line_num);
  }
  input_file.close();
}
int main() {
  ios_base::sync_with_stdio(SYNC);
  thread_num = thread::hardware_concurrency();
  string file_name;
  while (getline(cin, file_name))
    file_process(file_name);
  return 0;
}
