### Part 1
**输入文件要求：**

基础字典(DictFile): count+'\t'+pw （比如：basic_dic.txt）

训练字典(TrainFile): count+'\t'+pw （比如：train_dic.txt）

测试文件(TestFile): count+'\t'+pw （比如：test_set.txt）

需要强调的是，base_dic需要与test_set的来自同一语言，且basic_dic为较弱、较大（最好大于100万）的口令集，比如中文为Tianya, 英文为Rockyou。train_dic需要与test_set越接近越好，即语言相同，password policy相同，且网站类型最好比较接近，比如都同是来自社交网站。

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

**输出文件：**

得分文件(ScoreFile): pw+'\t'+psmScore (比如：PSM_result.txt)

### Part 3

**具体运行方式：**

1. Linux下编译源码 g++ fuzzypcfg_all_pw.cpp -o fuzzypcfg_all_pw

2. 运行格式：
./fuzzypcfg_pw DictFile TrainFile TestFile ScoreFile

3. 测试用例：
./fuzzypcfg_pw data/basic_dic.txt data/train_dic.txt data/test_set.txt data/PSM_result.txt

4. 运行结果：
测试集的PSM得分会输出到得分文件中，格式为 pw+'\t'+strength，具体可见data目录下的输出文件

5. 若直接使用run.sh脚本，可统计程序运行效率
./run.sh

**终端输出如下信息：**

> 运行时间(ms): 11 <br> 测试口令(个): 1000000 <br>
每秒可测试口令数(个/s): 90909
