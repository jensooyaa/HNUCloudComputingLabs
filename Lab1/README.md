# Lab 1: “Super-fast” Sudoku Solving

Enter in the folder you have cloned from our lab git repo, and pull the latest commit. 

`git pull`

You can find this lab1's instruction in `Lab1/README.md` 

All materials of lab1 are in folder `Lab1/`

## 1. Overview

Implement a Sudoku solving program, using multiple threads or multiple processes, running on a single machine. Try to **utilize all your CPU cores** and make your program **run as fast as possible**! 

实现一个数独解决程序，使用多个线程或多个进程，运行在一台机器上。 试着**利用你所有的CPU核心**，让你的程序**尽可能快地运行**!  

### Goals

* Practice basic parallel programming skills, such as using multiple threads/processes;
* 练习基础的并行编程技能，例如使用多线程/进程
* Get familiar with Unix OS environment development (eg., file I/O, get timestamp);
* 熟悉Unix操作系统环境开发(例如: 文件I/O，获取时间戳)
* Get familiar with source code version control tools (git), and learn to collaborate with others using github;
* 熟悉源代码版本控制工具(git)，学习使用github与他人协作  

## 2. Background

### 2.1 Introduction to Sudoku

Sudoku (originally called Number Place) is a logic-based combinatorial number-placement puzzle. 

数独(Sudoku，原名Number Place)是一种基于逻辑的组合数字放置谜题。  

You are given a 9×9 board of 81 squares logically separated into 9 columsn, 9 rows, and 9 3×3 subsquares. The goal is, given a board with some initial numbers filled in (we call it a **Sudoku puzzle**), fill in the rest of the board so that every column, row, and subsquare have all the digits from 1 to 9 and each digit appears only once (we call it a **Sudoku solution**).

给你一个9×9的板子，上面有81个正方形，逻辑上分成9列、9行和9个3×3子正方形。 我们的目标是,给定一个板子和一些初始数据填写(我们称之为一个**数独题** ),使用1到9的数字来填写的板子中的每一列,每一行,每一个子正方形,并且每个数字只出现一次(我们称之为**数独解**)。  


 <u>An example Sudoku puzzle:</u>

<img src="src/Sudoku_puzzle.png" alt="Sudoku" title="Sudoku puzzle" style="zoom:67%;" />

 <u>An example Sudoku solution to above puzzle:</u>

<img src="src/Sudoku_answer.png" alt="Sudoku" title="Sudoku answer" style="zoom:67%;" />

### 2.2 Some useful resources

If you have no idea about what algorithms can be used to solve Sudoku puzzles, we suggest you read [this](https://rafal.io/posts/solving-sudoku-with-dancing-links.html). To simplify your work, we have provided a simple [implementation](src/Sudoku/) `(Lab1/src/Sudoku`) of 4 Sudoku solving algorithms (some are slow, some are fast), but without using multiple threads/processes. The two files *test1* and *test1000* contain many puzzles for you to test. 

如果你不知道什么算法可以用来解决数独谜题，我们建议你阅读[这个](https://rafal.io/posts/solving-sudoku-with-dancing-links.html)。 

为了简化您的工作，我们提供了一个简单的[实现](src/Sudoku/) `(Lab1/src/Sudoku )`中的4个Sudoku求解算法(有些慢，有些快)，但不使用多线程/进程。 两个文件*test1*和*test1000*包含许多要测试的谜题。  

Of course, you are always encouraged (not mandatory) to implement those algorithms by yourselves and even your own algorithms (if you have time).

当然，我们总是鼓励(不是强制性的)您自己实现这些算法，甚至是您自己的算法(如果您有时间的话)。  

## 3. Your Lab Task

### 3.1 Write a program 

Implement a program which satisfies the following requirements:

实施满足下列要求的计划:  

#### 3.1.1 Program input and output

##### **3.1.1.1 Input** 

1. Your program **<u>must</u>** have no arguments during start. Attention, your program must be called *sudoku_solve*,  just typing `./sudoku_solve` and your program will run correctly.

   你的程序**<u>必须在启动时</u>**没有参数。 注意，你的程序必须被称为`sudoku_solve`，只需要输入`./sudoku_solve `，您的程序将正确运行。  

2. But after start, your program should be able to read multiple strings from ***stdin***, where each string is separated by a line-break. Each string is a **name of a file**, which contains one or more Sudoku puzzles that your program is going to solve.

   但是在开始之后，你的程序应该能够从***stdin***中读取多个字符串，其中每个字符串由一个换行符分隔。 每个字符串是一个文件**的**名，它包含一个或多个你的程序将解决的数独谜题。  

3. In the input file, **each line** is a Sudoku puzzle that needs to be solved. Each line contains 81 decimal digits. The 1st-9th digits are the 1st row of the 9×9 grid, and the 10th-18th digits are the 2nd row of the 9×9 grid, and so on. Digit 0 means this digit is unknown and your program needs to figure it out according to the Sudoku rules described above.

   在输入文件中，**每一行**是一个需要解决的数独谜题。 每行包含81位十进制数字。 第1 ~ 9位是9×9网格的第一行，第10 ~ 18位是9×9网格的第2行，以此类推。 数字0表示这个数字是未知的，你的程序需要根据上面描述的数独规则来计算它。

**Example contents**

<img src="src/Input_file.png" alt="Input file" title="Input file" style="zoom:67%;" />

**Example input**

```
./test1 
./test2
./test3
```

##### 3.1.1.2 Output

For each test case, you just only output the Sudoku solutions. And don't forget, the output order should correspond with the input order of Sudoku puzzles.

对于每个测试用例，您只输出Sudoku解决方案。 不要忘记，输出顺序应该与数独谜题的输入顺序相对应。  

**Example output**

```
312647985786953241945128367854379126273461859691285473437592618569814732128736594
693784512487512936125963874932651487568247391741398625319475268856129743274836159 
869725413512934687374168529798246135231857946456319872683571294925483761147692358
693784512487512936125963874932651487568247391741398625319475268856129743274836159
364978512152436978879125634738651429691247385245389167923764851486512793517893246
378694512564218397291753684643125978712869453859437261435971826186542739927386145
```

**Output order requirement**

In the example of input above, the order of filename entered is `./test1`, `./test2` and `./test3`. So, you should output the solutions of Sudoku puzzles in file `test1` firstly, then file `test2` and finally file `test3`. Needless to say, the solutions should be outputed in the same sequence as the puzzles are inputted in.

在上面输入的例子中，文件名的输入顺序是`./test1 `, `./test2`和`./test3`。 因此，您应该首先在文件`test1`中输出数独谜题的解决方案，然后文件`test2`，最后文件`test3`。 不用说，答案应该以输入谜题的相同顺序输出。  

In the example of output above, the 1st line is the solution of Sudoku puzzle in file `test1`. After that, the 2nd line and 3rd line are the solutions of 1st and 2nd Sudoku puzzles in file `test2`. Finally, the 4th line, 5th line and 6th line are the solutions of 1st, 2nd and 3rd Sudoku puzzles in file `test3`. 

在上面的输出示例中，第一行是`test1`文件中的数独谜题的解决方案。 然后，第二行和第三行是文件`test2`中第1和第2个数独谜题的答案。 最后，第4行、第5行和第6行是`test3`文件中第1、2和3个数独谜题的答案。  

#### 3.1.3 Implementation requirements 

##### 3.1.3.1 Basic version

Your program should be able to: 

1.  Accept **one** input file name, and the size of the input file is smaller than 100MB. 
2.  Successfully solve the puzzles in the input file, and output the results in the format described before.
3.  Use multiple threads/processes to make use of most of your machine's CPU cores.

\[Tips\]: 1) Use event queue to dispatch tasks and merge results to/from worker threads. 2) Dynamically detect how many CPU cores are there on your machine, in order to decide how many threads/processes your program uses. 3) Be careful about the contention among multiple threads/processes

你的程序应该能够:  

1. 接受**一个**输入文件名，输入文件大小小于100MB。  

2. 成功解决输入文件中的谜题，并以前面描述的格式输出结果。  

3. 使用多线程/进程可以充分利用机器的大部分CPU核心。  

\[提示]：1)使用事件队列来调度任务，并将结果合并到工作线程中。 2)动态检测有多少CPU核在你的机器上，以决定有多少线程/进程，你的程序使用。 3)小心多线程/进程之间的争用  

##### 3.1.3.2 Advanced version

Your program should be able to: 

1. Complete all the requirements in the basic version.
2. Accept **any number of** input file names, and the size of input file can be **any large** (as long as it can be stored on your disk)
3. When the program is solving puzzles in the previously input file(s), the program can **meanwhile accept more input file names from *stdin***.

\[Tips\]: 1) Use a dedicated thread to accept input; 2) To avoid consuming all the memory, read different parts of the file into memory and solve them one by one; 3) You are encouraged to try more optimizations such as cache coherency processing.

你的程序应该能够:  

1. 完成基本版本中的所有要求。  

2. 接受**任意数量的**输入文件名，输入文件的大小可以**任意大**(只要它可以存储在您的磁盘上)  

3. 当程序在解决之前输入文件中的谜题时，程序可以**同时从*stdin***接受更多的输入文件名。  

\[提示\]:1)使用专用线程接受输入; 2)为避免占用全部内存，请将文件的不同部分读入内存，并逐个解决; 3)鼓励你尝试更多的优化，如缓存一致性处理。  

### 3.2. Test script

You can test your program using the script (Lab1.sh) that comes with this Lab.

您可以使用本Lab附带的脚本(Lab1.sh)测试您的程序。  

##### 3.2.1 Notes

1. You can use the script on most Linux environments

   您可以在大多数Linux环境中使用该脚本  

2. Requires support for the **screen** command

   需要支持的**screen**命令  

​		You can use "***which screen***" to see if the screen command is already installed, if not you can refer to the following command download:

你可以使用“***which screen***”来查看screen命令是否已经安装，如果没有，你可以参考以下命令下载:  

```shell
		ubuntu: apt-get install screen

		centos: yum install screen
```

3. The executable file can only be named **sudoku_solve**

   可执行文件的名称只能为**sudoku_solve**  

4. sudoku_solve executable file, Lab1.sh script should be placed in the same directory

    sudoku_solve可执行文件，Lab1.sh脚本应放在同一目录下  

5. If your file system is not in **ext4** format, the performance test may not succeed and only the basic test can be performed.

   如果文件系统不是**ext4**格式，可能会导致性能测试失败，只能执行基本测试。

   ​	You can see which path mounted ext4 disks  in the following way: 

   您可以通过以下方式查看ext4磁盘挂载的路径:  

   ```shell
   	df -h --type=ext4
   ```

   <img src="src/where_ext4.png" alt="Sudoku" title="where ext4" style="zoom:100%;" />

6. The script will generate a subfolder with Basic(Advanced)\_Result and Basic(Advanced)_Answer, Result is your output and Answer is the reference output. At each run, the script will delete the two files , so if you need this data, please copy it first before running the script.

   脚本将生成一个基本(高级)\结果和基本(高级)_Answer的子文件夹，结果是你的输出，答案是参考输出。 每次运行时，脚本都会删除这两个文件，所以如果您需要这些数据，请在运行脚本之前先复制它们。  

7. The time taken for script presentation is relative, each time there will be a relatively fixed processing time. For example, your program used 1300ms to solve the sudoku problem, but the script preparation took 800ms. eventually, the script will show 2100ms. Also everyone's configuration and performance is different, resulting in different times, which means you only need to keep optimizing on your machine, not comparing it with others. Please be assured that the same environment will be used for the final scoring.

   脚本呈现所花费的时间是相对的，每次都会有一个相对固定的处理时间。 例如，您的程序使用1300ms来解决数独问题，但是脚本准备需要800ms。 最终，脚本将显示2100ms。 此外，每个人的配置和性能都是不同的，导致不同的时间，这意味着您只需要在您的机器上进行优化，而不需要与其他机器进行比较。 请放心，最终评分将使用相同的环境。  

8. (**Very important**) If you want to get a high score (script test), it is better to flush the data in the buffer in time.

   (**非常重要**)如果你想要得到一个高分(脚本测试)，它是最好的刷新数据在缓冲区的时间。  

##### 3.2.2 Script Usage

```shell
		sudo  ./Lab1.sh  test_group answer_group
```

Parameter explanation：

​		The script takes two parameters	

​		Para1(For example: test_group ) : A file that create by yourself. This file is placed in the path of the different test files. For example, if the test file group contains: . /test1 . /test1000 two input test files, the structure is as follows：

​		Para1(例如:test_group):由自己创建的文件。 该文件被放置在不同测试文件的路径中。 例如，测试文件组包含: ./ test1 ./test1000两个输入测试文件，结构如下:  

<img src="src/test_group.png" alt="Sudoku" title="test group" style="zoom:100%;" />

​		Para2(For example: answer_group) : A file like parameter 1 but with the path to the answer to the test file. For example, if the test file group contains: . /test1 . /test1000 two input test files, the answer file group contains: . /answer1 . /answer1000 , and the structure is as follows：

​		Para2(例如:answer_group):一个类似于参数1的文件，但带有测试文件的答案的路径。 例如，测试文件组包含: ./ test1 ./test1000两个输入的测试文件，回答文件组包含: ./ answer1 ./answer1000，结构如下:  

<img src="src/answer_group.png" alt="Sudoku" title="answer group" style="zoom:100%;" />

You can create your own test files and put in the combinations you want.

Note that this output below means that you are missing a line break at the end of your test file, which will not be recognized. Of course, the path of your answer file should be in the same order as the test path.

您可以创建自己的测试文件，并放入您想要的组合。  

请注意，下面的输出意味着您在测试文件的末尾丢失了一个换行符，它将无法被识别。 当然，回答文件的路径应该与测试路径的顺序相同。  

<img src="src/Wrong_Example.png" alt="Sudoku" title="Wrong Example" style="zoom:100%;" />

An example：

<img src="src/An_example.png" alt="Sudoku" title="An example" style="zoom:100%;" />

## 4. Lab submission

Please put all your code in folder `Lab1` and write a `Makefile` so that we **can compile your code in one single command** `make`. The compiled runnable executable binary should be named `sudoku_solve` and located in folder `Lab1`. If you do not know how to write `Makefile`, you can find a simple example in `Lab1/src/Sudoku`. Please carefully following above rules so that TAs can automatically test your code!!!

Please submit your lab program and performance test report following the guidance in the [Overall Lab Instructions](../README.md) (`../README.md`)

请把你所有的代码放在`Lab1`文件夹中，然后写一个`Makefile`，这样我们**就可以在一个命令**`make`中编译你的代码。 编译后的可执行二进制文件应该命名为`sudoku_solve`，并位于`Lab1`文件夹中。 如果你不知道如何编写`Makefile`，你可以在`Lab1/src/Sudoku`中找到一个简单的例子。 请仔细遵守以上规则，以便助教能够自动测试你的代码!!  

请按照[实验总体说明](../README.md) (`../README.md`)中的指导提交你们的实验计划和性能测试报告。  

## 5. Grading standards

1. You can get 38 points if you can: 1) finish all the requirements of the basic version, and 2) your performance test report has finished the two requirements described before. If you missed some parts, you will get part of the points depending how much you finished

   如果可以，你可以得38分: 1)完成了基础版的所有要求，2)性能测试报告完成了之前描述的两个要求。 如果你错过了一些部分，你将得到部分的分数取决于你完成了多少  

2. You can get 40 points (full score) if you can: 1) finish all the requirements of the advanced version, and 2) your performance test report has finished the two requirements described before. If you missed some parts, you will get part of the points depending how much you finished.

   如果可以，你可以得40分: 1)完成高级版本的所有要求，2)您的性能测试报告已完成前面描述的两个要求。 如果你错过了一些部分，你将得到部分的分数取决于你完成了多少。  
