#include <assert.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <sys/time.h>
#include <thread>

#include "sudoku.h"
#include "threadpool.h"
using namespace std;

// ios和stdio的同步是否打开
#define SYNC 0
#define DEBUG 0
double total_time_start,total_time_end;
double time_start,time_end;
double sec;

ThreadPool thread_pool;
int thread_num = 1;
char one_puzzle[128];
const int puzzle_buf_num = 10240;
int puzzle_buf[puzzle_buf_num][N];

double now() { // 返回时间
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (double)tv.tv_sec * 1000000 + (double)tv.tv_usec;
}

void init() {
  if (DEBUG)
    cout << "init ThreadPool...." << '\n';
  ios_base::sync_with_stdio(SYNC);
  thread_num = thread::hardware_concurrency();
  thread_pool.start(thread_num);
  if (DEBUG)
    cout << "ThreadNum: " << thread_num << '\n';
}

void del() {
  if (DEBUG)
    cout << "destroy ThreadPool...." << '\n';
  thread_pool.close();
  if (DEBUG)
    cout << "destroy success" << '\n';
}

// 解数独
int solve(int start, int end) {
  for (int i = start; i < end; i++)
    solve_sudoku_dancing_links(puzzle_buf[i]);
  if (DEBUG) {
    thread::id tid = this_thread::get_id();
    cout << "[tid]: " << tid << " | "
         << "[start]: " << start << " | "
         << "[end]: " << end << '\n';
  }
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
  if (DEBUG)
    total_time_start = now();
  ifstream input_file(file_name, ios::in);
  vector<future<int>> results;
  while (!input_file.eof()) {
    if (DEBUG)
      time_start = now();
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
    if (DEBUG)
      cout << "current data line_num: " << line_num << '\n';

    // 分数据
    int start = 0, end = 0, len = (line_num + thread_num) / thread_num;
    for (int i = 0; i < thread_num; i++) {
      end = (start + len >= line_num) ? line_num : start + len;
      results.emplace_back(thread_pool.enqueue(solve, start, end));
      start += len;
    }
    if (DEBUG)
      cout << "wait task accomplish..." << '\n';
    for (auto &&result : results)
      result.wait();

    // 输出数据
    if (DEBUG)
      cout << "print data" << '\n';
    print(line_num);
    if (DEBUG) {
      time_end = now();
      sec = (time_end - time_start) / 1000000.0;
      cout << "[time]:" << 1000 * sec << "ms" << '\n';
      cout << "------------------------------------------------------" << '\n';
    }
  }
  input_file.close();
  if (DEBUG) {
    total_time_end = now();
    sec = (total_time_end - total_time_start) / 1000000.0;
    cout << "[total time]:" << 1000 * sec << "ms" << '\n';
    cout << "------------------------------------------------------" << '\n';
  }
}
int main() {
  init();
  string file_name;
  while (getline(cin, file_name))
    file_process(file_name);
  del();
  return 0;
}
