#include "sudoku.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
// #include <sys/sysinfo.h>

int main(int argc, char *argv[]) {

  // int nprocs = get_nprocs();

  init_neighbors(); // 记录邻点位置neighbors[81][20]数组

  char filename[20];
  while (scanf("%s", filename) != EOF) {
    FILE *fp = fopen(filename, "r"); // 以只读模式打开文件
    char puzzle[128];
    int total_solved = 0;
    int total = 0;

    bool (*solve)(int) = solve_sudoku_dancing_links;

    while (fgets(puzzle, sizeof puzzle, fp) !=
           NULL) { // 读取文件流内容到puzzle中
      if (strlen(puzzle) >= N) {
        ++total;
        input(puzzle); // 输入到board数组中
        if (solve(0)) {
          ++total_solved;
          if (!solved())
            assert(0);
        } else {
          printf("No: %s", puzzle);
        }
        for (int i = 0; i < N; i++) {
          printf("%d", board[i]);
        }
        printf("\n");
      }
    }
  }

  return 0;
}
