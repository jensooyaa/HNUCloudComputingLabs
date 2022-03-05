# Cloud Computing: Overall Lab Instruction

<!--**This is the repo containing all the lab materials for undergraduate course CS06142 "Cloud Computing Techniques" at Hunan University**-->

<！——**这是包含湖南大学本科课程 CS06142“云计算技术”所有实验材料的仓库**——>

赢麻了 fxh

## 1. Overview

There are **4 labs in total** in this course. All the materials of each lab are under folders Lab1-4 in this repo. Please clone the lab git repo onto your local computer,

`git clone https://github.com/1989chenguo/CloudComputingLabs.git`

and always track our latest lab materials using the following commands (should first enter the folder you have cloned from our lab repo)

`git pull`

You can find this overall lab instruction in `README.md` in the root folder.

Please **carefully read the overall lab instruction before you do anything**.

Also, please **carefully read each lab's instruction** ([Lab1](Lab1/README.md), [Lab2](Lab2/README.md), [Lab3](Lab3/README.md), [Lab4](Lab4/README.md)) to get each lab's task, background, requirements, etc.

本课程共有四堂实验课。 所有实验的资料都在这个代码仓库的 Lab1-4 文件夹下。 请克隆这个代码仓库到您的本地计算机上，

并始终使用以下命令跟踪我们最新的实验资料(应首先进入您从我们的实验仓库克隆的文件夹)

你可以在根目录下的 README.md 文档中找到这个完整的实验说明。

在你做任何事情之前，请仔细阅读整个实验说明。

同时，请仔细阅读各实验说明书(Lab1、Lab2、Lab3、Lab4)，了解各实验的任务、背景、要求等。

## 2. Group collaboration

Each student should register your own github account. Group members should use **git and github** to collaborate.

All the labs are done in the unit of group, i.e., a group only needs to submit one piece of code for each lab. However, each group member should make enough contribution to the lab. Teaching assistants will check the **git commit history** to evaluate each one’s contribution.

每个学生都应该注册自己的 github 账号。 小组成员应该使用**git 和 github**进行协作。

所有的实验都是以小组为单位完成的，即一个小组只需为每个实验提交一段代码。 但是，每个小组成员都应该为实验室做出足够的贡献。 教学助理将检查**git 提交历史记录**，以评估每个人的贡献。

## 3. Code submission

Each group should create a code repo for our course (create your own group's repo, do not push onto my course lab repo!). The group leader should send an email to TA telling us your group's lab git repo address. For example, https://github.com/group1/CloudComputingLabs.git`

每个组应该为我们的课程创建一个代码仓库(创建自己组的仓库，不要推到我的课程实验仓库!) 组长应该给 TA 发邮件告诉我们你们组的实验代码仓库地址。 例如,https://github.com/group1/CloudComputingLabs.git

**All the lab code should be submitted through pushing to your group's github code repo.** Teaching assistants will checkout your commit, and read and test your codes from the above repo address you provided us. The code of different lab should be in different folders, named Lab1/Lab2/Lab3/Lab4, respectively (following the same structure of this repo). Please note that your lab folder name should be exactly same as above (be careful about the first capital letter and no space before the number), otherwise your code may fail in our TAs' automatic testing scripts. All lab codes should be in the same course git repo of your group.

**所有的实验代码应该通过推到你的小组的 github 代码仓库提交。 **助教将检查您的提交，并从您提供给我们的上述仓库地址阅读和测试您的代码。 不同 lab 的代码应该放在不同的文件夹中，分别命名为 Lab1/Lab2/Lab3/Lab4(与本次代码仓库的结构相同)。 请注意您的实验文件夹名称应该与上面的名称完全相同(注意第一个大写字母，数字前没有空格)，否则您的代码可能会在我们的助教的自动测试脚本中失败。 所有的实验代码应该在同一课程的您的小组的代码仓库下。

Please write a README.md to each lab code folder, briefly introducing how to run your lab code (including how to set the environment, provide the input, and explain the output, etc.). Keep the README short and clear! Also, your code should be well commented so that other people can understand without asking you.

请编写 README.md 文档到每个实验的代码文件夹下，简要介绍如何运行您的实验代码(包括如何设置环境，提供输入，并解释输出等)。 保持 README 的简短和清晰! 另外，你的代码应该有很好的注释，这样其他人不用问你也能理解。

## 4. Environment requirement

### 4.1 OS requirement

All the labs should be tested and runnable on UNIX-like operating systems, such as Linux distributions (e.g., Ubuntu, CentOS) and MacOS. We highly recommend you to use Linux distributions such as Ubuntu.
If you only have windows PC or laptops, install a UNIX VM and do experiments on the VM.

所有的实验都应该在类 unix 的操作系统上进行测试和运行，例如 Linux 发行版(例如 Ubuntu, CentOS)和 MacOS。 我们强烈建议您使用 Linux 发行版，如 Ubuntu。

如果只有 windows PC 或笔记本电脑，请安装一台 UNIX 虚拟机，并在虚拟机上进行实验。

### 4.2 Programming language

Any programming languages are permitted in all labs, such as C/C++, Java, Go, Python, Perl. But for performance consideration, we highly recommend you to use C/C++ or Go !!!

任何编程语言都允许在所有的实验，如 C/ c++， Java, Go, Python, Perl。 但出于性能考虑，我们强烈建议您使用 C/C++或 Go !!

### 4.3 Try to only use standard API

To make your program portable, try your best to only use standard & widely available functions and normal libraries (such as `glibc`, `C++ STLs` and some typical math libraries). All the labs should only use standard system API defined by POSIX specification or Linux man page specification. We prefer to use standard POSIX API, so your code can be easily runnable on various kind of UNIX-like systems (instead of only on Linux).

为了使你的程序具有可移植性，尽量只使用标准的和广泛可用的函数和普通的库(如 `·glibc`， `c++ STLs`和一些典型的数学库)。 所有的实验室应该只使用 POSIX 规范或 Linux 手册页规范定义的标准系统 API。 我们更喜欢使用标准的 POSIX API，这样您的代码就可以轻松地在各种类 unix 系统上运行(而不仅仅是在 Linux 上)。

## 5. Grading

Grading details are specified in each lab's instruction document, please carefully read them [Lab1](Lab1/README.md), [Lab2](Lab2/README.md), [Lab3](Lab3/README.md), [Lab4](Lab4/README.md).

Besides, we have the following 3 overall grading requirements applicable to all the 4 labs:

1. **DO NOT copy** others' code (either from the Internet or from your classmates), otherwise your group (every member and the leader) will got **zero point** in the lab. However, we encourage to communicate with other group and learn from each other. But do remember to write the code yourself and not copy.
2. **DO NOT miss the deadline**, otherwise your group (every member and the leader) points will be reduced accordingly.
3. Typically, your group (every member and the leader) will get same points in each lab, unless we find severely **unfair contribution** in the git commit history. In the overall grading, the leader will get some more points as bonus.

评分细则在各实验室说明书中有详细说明，请仔细阅读[Lab1](Lab1/README.md)、[Lab2](Lab2/README.md)、[Lab3](Lab3/README.md)、[Lab4](Lab4/README.md)。

此外，我们有以下 3 个整体评分要求，适用于所有 4 个实验:

1. **不要抄袭别人的代码**(无论是网络还是同学的)，否则你的小组(每个成员和领导)将在实验得到零分。 但是，我们鼓励与其他小组交流，互相学习。 但是一定要记住自己写代码，不要抄袭。
2. **请不要错过**的截止时间，否则您的团队(每个成员和领导)的积分将会相应减少。
3. 通常情况下，你的团队(每个成员和领导)在每个实验都得到相同的分数，除非我们在 git 提交历史中发现严重的不公平贡献。 在整体评分中，领导者会得到更多的积分作为奖励。
