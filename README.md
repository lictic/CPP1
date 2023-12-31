# Async Lab 2023暑假招新（C++方向）第一次项目测试
> 写在前面：
> 其实我们在直接做项目还是先给各位一点时间学习C++的基础语法这件事情上纠结了一段时间。最后我们的决定是直接做项目。毕竟各位都是大一升大二的同学，不能把对新大一的要求放到你们身上，只有提高难度才能确保各位的能力可以达到实验室的要求。<br>
> 如果你没有接触过C++/Java等面向对象的语言，那么请先花时间学习C++类和对象的相关知识。我们是C++方向，因此尽管C++向下兼容C，但是我们并不接受纯C的代码。<br>
> 在这个暑假，你们会有三次项目考核，后两次都会在前一次的基础上增加新的功能。所以，请确保各位在自己的代码中写好了注释，避免出现看之前自己写的代码看不懂的情况。
***
## 项目介绍：
**“你所热爱的，就是你的生活。”**<br><br>
成都信息工程大学知名校友、Bilibili创始人陈睿说。这句话感染者一代又一代的成信学子，鼓励着他们以梦为马，以热爱为动力，向着自己的美好未来拼搏奋进。<br><br>
你们是一群热爱编程的成信人。你们也希望将自己的热爱投射进生活。所以你们决定追随这位成都信息工程大学优秀校友的步伐，写一个视频网站，将其命名为**Pilipili**，简称**P站**。你们擅长的是C++，所以你们需要编写一个后端程序，用于**存储用户账户信息**。

## 项目要求：
- **语言：C++**（不允许使用纯C）
- **代码管理方式：CMake**（即包含一个可以生成出可执行文件的CMakeLists.txt）(请将你的CMake目标命名为`Main`)  
- **上传代码方式：上传至Github仓库**（仓库详细说明见下一个大项）
- **测试环境：** Ubuntu 22.04(latest-lts) x86_64 (我们会在测试时使用这个版本的Ubuntu)  **字符编码**: UTF-8
- **功能实现：**
- 1. 账户信息包含：用户名（最多15位，不可重复）、性别、出生日期、邮箱（最多30位）、UID（从1开始，按照输入顺序自动生成）、硬币（初始值100，不能为负）；
- 2. 从键盘中读一个用户的账户信息（按照用户名、性别、出生日期、邮箱的顺序，输入格式见下）；
- 3. 可以输出所有用户的账户信息（输出格式见下）；
- 4. 可以按照用户名删除某个用户，在删除完成之后输出所有用户的账户信息；
- 5. 可以按照用户名修改某个用户的硬币值（格式见下）。
- 6. 可以按照用户硬币数从高到低排序，硬币数相同的按照年龄从大到小排序，然后输出所有用户的账户信息；
- 7. 程序可以在重启之后仍然记忆所有用户的信息。
- **代码风格(额外加分项)：** 请参考[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)进行编码。  

<br>  

## 输入输出格式：[输入:我们测试脚本给你程序的输入,输出:你程序输出的内容] <BR>
每一项功能执行完成后应直接回到功能列表，除非用户选择退出程序，不要有按任意键继续之类的设计，这可能会导致测试脚本卡住( <br>
- **功能列表**  (我们不会限制你的功能菜单应该长什么样，你甚至可以默认不显示功能菜单，但是功能选择的顺序必须与功能实现一致，以下为示例)
> 1. 添加用户账户
> 2. 输出所有用户账户信息
> 3. 删除用户账户
> 4. 修改用户硬币数
> 5. 排序用户账户
> 6. 保存并退出(注意: 我们可能不会正常退出你的程序! 请确保你的程序在异常退出时也能保存用户信息) <br> 

  我们的输入会以这样的形式给出： `1`然后我们会加上回车。
- **添加用户账户** (形如`test`的内容是我们的输入) [您此处的提示信息不必与我们的示例一致]
> 请输入用户名（最多15位，不可重复）：`test`<br>
> 请输入性别（M/F/其他/沃尔玛购物袋）：`M`<br>
> 请输入出生日期（YYYY-MM-DD）：`2000-01-01`<br>
> 请输入邮箱（最多30位）：`123456@test.com`<br>
> 添加成功！<br>
- **输出所有用户账户信息**
> 在输出的每行用户账户信息的时候，请在**每条数据的开头加上`$`符号**，以便于我们的测试脚本进行判断。<br>
> 输出的顺序可以调换，但请确保不同种类的数据之间有换行符隔开,且只有一条数据的开头需要加上$。例如:<br>
> 提示信息的内容必须一致(用户名: 、性别: 、出生日期: 、邮箱: 、UID: 、硬币: 、年龄: ),注意是英文(半角)冒号加一个空格。<br>
> $用户名: test<br> 性别: 男<br> 出生日期: 2000-01-01<br> 邮箱: 123456@test.com<br> UID: 1<br> 硬币: 100<br> 年龄: 23<br>
> $用户名: test2<br> 性别: 其他<br> 出生日期: 1998-02-01<br> 邮箱: 10001@test.com<br> UID: 2<br> 硬币: 100<br> 年龄: 25<br>
- **删除用户账户** (形如`test`的内容是我们的输入,以下均是)
> 请输入要删除的用户名：`test`<br>
> 删除成功！<br>
- **修改用户硬币数** 
> 请输入要修改的用户名和硬币数：`test 100`<br>
> 修改成功！<br>
- **排序用户账户**
> $用户名: test2<br> 性别: 男<br> 出生日期: 1998-02-01<br> 邮箱:10001@test.com<br> UID: 2<br> 硬币: 100<br> 年龄: 25<br>
> $用户名: test<br> 性别: 其他<br> 出生日期: 2000-01-01<br> 邮箱:123456@test.com<br> UID: 1<br> 硬币: 100<br> 年龄: 23<br>

## 我们建议你完成这个项目之前需要掌握的内容：
- C语言的知识
- C++类和对象的基本知识（至少包括类的定义、构造与析构函数）
- C或C++风格的文件读写操作
- C或C++风格的控制台读写操作
- 常用的STL的知识（建议先学习string，vector）
- 常见的排序算法
<br><br>您可以一边学习，一边通过本项目来掌握这些知识。

## Github仓库说明：
我们会在实验室自己的团队中创建一个总库，用于存放项目要求和测试脚本。你们需要先克隆（Clone）这个库到自己的账户下，然后将代码上传到**自己账户下**的这个库。<br>
我们会设置一些测试点，通过一个测试点可以得到一定的分数。你可以在Github Actions页面中查看每个测试点是否通过（但你不能查看到所有测试点的详细信息）。<br>
如果你已经通过了所有的测试点并确定要提交代码，请在本仓库的issue里面打开一个新的issue，并根据模板进行填写，我们会在两天内对你的代码进行评审。并将结果附在issue里面 <br> 
请注意，**不要擅自修改我们的任何脚本**。我们的所有脚本将会统一的放在`.github`目录下，也就是不要修改该目录下的所有文件，如果有脚本问题，请联系我们。我们会在review时检查脚本是否被修改。**擅自修改脚本的同学，直接取消进入实验室的资格。**  
如果需要添加自己的测试项目，请在你的项目中正确配置CTest。自动化测试时会自动运行CTest。如不需要请忽略。  
