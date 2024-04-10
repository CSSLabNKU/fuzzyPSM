## README
本文件夹中包含**files**文件夹，可执行程序**fuzzyPSM.exe**和自动执行脚本**run.bat**，下面进行介绍。

### Part 1

files文件夹中最初应至少包含三个txt文件: 基础字典文件(示例中为base_dic.txt)、训练文件(示例中为train_dic.txt)、测试文件(示例中为test_set.txt)。

需要强调的是，base_dic需要与test_set的来自同一语言，且base_dic为较弱、较大（最好大于100万）的口令集，比如中文为Tianya, 英文为Rockyou。train_dic需要与test_set越接近越好，即语言相同，password policy相同，且网站类型最好比较接近，比如都同是来自社交网站。

三个输入文件的内容形如下：

391	123456 <br>
276	a123456 <br>
161	5201314 <br>
158	123456a <br>
154	111111 <br>
133	woaini1314 <br>
98	123123 <br>
.......

即，每一行形如"频数(为整数) \t 口令(为字符串)"。

### Part 2
程序运行需要设置四个文件（即字典文件base_dic.txt、训练文件train_dic.txt、测试文件test_set.txt、结果文件PSM_result.txt）所在的路径path。

为了方便使用，本文件夹中给出了一个脚本run.bat，四个文件的路径path已经设置好，即为"./files/base_dic.txt", "./files/train_dic.txt", "./files/test_set.txt",  "./files/PSM_result.txt" 。
 
双击该脚本文件run.bat即可自动运行程序fuzzyPSM.exe，并评测test_set.txt，得到（输出）结果文件PSM_result.txt。

可以根据实际情况，自行更改脚本里的文件路径path。


### Part 3

程序运行结束后，会生成评测结果，存储于"./files/PSM_result.txt"。每一行是一个double型的属于[0,1]浮点数，为测试文件test_set.txt中每个口令的评测结果（即口令出现的概率值）。