### Part 1
**Input File Requirements:**

Base Dictionary(DictFile): count+'\t'+pw （e.g.:basic_dic.txt）

Training Dictionary(TrainFile): count+'\t'+pw （e.g.:train_dic.txt）

Test Set(TestFile): count+'\t'+pw （e.g.:test_set.txt）

What should be **emphasized** are that: (1) "base_dic" is a large (e.g., with size larger than 1 million) and weak password set; (2) It needs to be from the same language as "test_set". For example, the 31.7 million Tianya dataset can be chosen as the Chinese base_dic, while the 32.6 million Rockyou  dataset can be chosen as the English base_dic,

And "train_dic" needs to be as close as possible to the "test_set", i.e., the same language and the same password policy. Moreover, it's better that the website types are similar, for example, both of them come from social network sites.

**Following is the example of contents of the three input files:**

391	123456 <br>
276	a123456 <br>
161	5201314 <br>
158	123456a <br>
154	111111 <br>
133	woaini1314 <br>
98	123123 <br>
.......

i.e., each line looks like "frequency(integer) \t password(string)".

### Part 2

**Output File：**

Score File(ScoreFile): pw+'\t'+PSMScore (e.g.:PSM_result.txt)

### Part 3

**Running Steps：**

In the current directory of the Linux system(../fuzzy_PSM test)

1. Running Format：./fuzzypcfg_all_pw DictFile TrainFile TestFile ScoreFile

2. Test Case：./fuzzypcfg_all_pw files/basic_dic.txt files/train_dic.txt files/test_set.txt files/PSM_result.txt

3. Test Results：The PSM score of the test set will be output to the score file in the format pw+'\t'+strength. The output file is in the ‘files’ directory.(PSM_result.txt)