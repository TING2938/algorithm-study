# top命令详解 - 简书
[![](https://cdn2.jianshu.io/assets/default_avatar/7-0993d41a595d6ab6ef17b19496eb2f21.jpg)
](https://www.jianshu.com/u/646868b8f790)

0.6912017.03.12 11:13:22字数 506阅读 19,436

### 这是一张top的图

![](https://upload-images.jianshu.io/upload_images/3906735-eee59207d2994671.png)

top.png

### 第一行

| 字符 | 含义 |
| --- | --- |
| top - 10:03:19 | 当前系统时间 |
| up 137 days , 10:40 | 系统已运行时间 |
| 2 user | 在线用户 |
| load average: 0.00, 0.01, 0.05 | 系统负载。三个数值分别为 1分钟、5分钟、15分钟前到现在的平均值。 |

> 2 user，包含系统用户。

* * *

### 第二行

| 字符 | 含义 |
| --- | --- |
| Tasks : 92 total | 总进程数 |
| 2 running | 正在运行的进程数 |
| 90 sleeping | 正在睡眠的进程数 |
| 0 stopped | 停止的进程数 |
| 0 zombie | 僵尸进程数 |

> 僵尸进程:一个子进程在其父进程没有调用wait()或waitpid()的情况下退出。这个子进程就是僵尸进程。如果其父进程还存在而一直不调用wait，则该僵尸进程将无法回收，等到其父进程退出后该进程将被init回收。

* * *

### 第三行

| 字符 | 含义 |
| --- | --- |
| %Cpu(s): 0.3 us | cpu占用率(%)，用户进程占用cpu百分率 |
| 0.3 sy | 系统占用cpu百分率 |
| 0.0 ni | 用户进程空间内改变过优先级的进程占用CPU百分比 |
| 99.3 id | cpu空闲率 |
| 0.0 wa | 等待IO的CPU时间百分比 |
| 0.0 hi | 硬中断（Hardware IRQ）占用CPU的百分比 |
| 0.0 si | 软中断（Software Interrupts）占用CPU的百分比 |

> cpu的使用情况

* * *

### 第四行

| 字符 | 含义 |
| --- | --- |
| KiB Mem : 1016916 total | 内存总量（我这里是1G） |
| 82280 free | 内存空闲量 |
| 233848 used | 内存使用量 |
| 700788 buff/cache | 缓存的内存量 |

> 内存使用率

* * *

### 第五行

| 字符 | 含义 |
| --- | --- |
| KiB Swap: 0 total | 交换区总量 |
| 0 free | 交换区空闲量 |
| 0 used | 交换区使用量 |

> 我这里没有swap分区，所以都为0

* * *

### 第六行

| 字符 | 含义 |
| --- | --- |
| PID | 进程号 |
| USER | 进程创建者 |
| PR | 进程优先级 |
| NI | nice值。越小优先级越高，最小-20，最大20（用户设置最大19） |
| VIRT | 进程使用的虚拟内存总量，单位kb。VIRT=SWAP+RES |
| RES | 进程使用的、未被换出的物理内存大小，单位kb。RES=CODE+DATA |
| SHR | 共享内存大小，单位kb |
| S | 进程状态。D=不可中断的睡眠状态 R=运行 S=睡眠 T=跟踪/停止 Z=僵尸进程 |
| %CPU | 进程占用cpu百分比 |
| %MEM | 进程占用内存百分比 |
| TIME+ | 进程运行时间 |
| COMMAND | 进程名称 |

> PR 越低优先级 越高，PRI(new)=PRI(old)+nice  
> PR中的rt为实时进程优先级即rt\_priority，prio=MAX\_RT\_PRIO - 1- p->rt\_priority  
> MAX\_RT\_PRIO = 99，prio大小决定最终优先级。这样意味着rt\_priority值越大，优先级越高而内核提供的修改优先级的函数，是修改rt\_priority的值，所以越大，优先级越高。  
> 例：改变优先级：进入top后按“r”–>输入进程PID–>输入nice值

### top命令（在进入top后使用）

> P：以占据CPU百分比排序  
> M：以占据内存百分比排序  
> T：以累积占用CPU时间排序  
> q：退出命令：按q键退出top查看页面  
> s：修改刷新时间间隔。按下s键，然后按下数字，即可修改刷新时间间隔为你输入的数字，单位为秒。例如：按下s键，在按数字1键，即可实现每秒刷新一次  
> k：终止指定的进程。按下k键-->再输入要杀死的进程的pid-->按enter键-->(选择信号类型，以数字标示，默认15为杀死)本步可省略按enter键（常用为-9）

kill信号大全：[http://www.2cto.com/os/201202/119425.html](https://link.jianshu.com/?t=http://www.2cto.com/os/201202/119425.html)

* * *

### 扩展

比`top`更好用的工具`htop`  
介绍：[http://www.jianshu.com/p/ece7700194d8](https://www.jianshu.com/p/ece7700194d8)

更多精彩内容，就在简书APP

"小礼物走一走，来简书关注我"

还没有人赞赏，支持一下

[![](https://cdn2.jianshu.io/assets/default_avatar/7-0993d41a595d6ab6ef17b19496eb2f21.jpg)
](https://www.jianshu.com/u/646868b8f790)

### 推荐阅读[更多精彩内容](https://www.jianshu.com/)

*   TOP是一个动态显示过程,即可以通过用户按键来不断刷新当前状态.如果在前台执行该命令,它将独占前台,直到用户终止该...
    
*   top是Linux较为常用的命令，可以监控服务器的CPU、内存、进程的运行情况，话不多说，直接操作。 输入top即...
    

*   Linux Top命令详解 top命令是Linux环境下常用分析工具，能够实时显示系统中各个进程的资源占用状况 可...
    
*   又来到了一个老生常谈的问题，应用层软件开发的程序员要不要了解和深入学习操作系统呢？ 今天就这个问题开始，来谈谈操...
    
    [![](https://upload-images.jianshu.io/upload_images/1416484-7b35826e54ddab2a.jpg?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)
    ](https://www.jianshu.com/p/2b993a4b913e)
*   Linux 进程管理与程序开发 进程是Linux事务管理的基本单元，所有的进程均拥有自己独立的处理环境和系统资源，...
    
    [![](https://upload-images.jianshu.io/upload_images/1678197-fee2f7188d347006.png?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)
    ](https://www.jianshu.com/p/51890c45a799)
*   有时，我会先设计一个地点， 然后将它不断地延伸拓展，直到整个世界跃然纸上—— 这是一种由小及大的方式;而有时我会选...
    
    [![](https://cdn2.jianshu.io/assets/default_avatar/3-9a2bcc21a5d89e21dafc73b39dc5f582.jpg)
    澈了个丹](https://www.jianshu.com/u/331c1a5d2787)阅读 141评论 0赞 0
    

*   [![](https://upload-images.jianshu.io/upload_images/1445750-b9fe767026c6996b.png?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)
    ](https://www.jianshu.com/p/55ee8b27f333)
*   记得小学三年级的暑假第一次接触到武侠小说，是金庸的《倚天屠龙记》，虽然那时有好多字都不认识，但依然深深的沉迷其中，...
    
    [![](https://upload-images.jianshu.io/upload_images/4196741-15f3498c5077eb11.jpg?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)
    ](https://www.jianshu.com/p/06def4104432)
*   还记得上初中的时候，女生们总是喜欢叫着自己的小伙伴一起上厕所，一起买水，一起回家，其实就跟恋爱差不多了，干什么都要...