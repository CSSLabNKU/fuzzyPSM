## README
This folder contains a folder named "files", an executable program named "fuzzypsm.exe" and an automatic execution script named "run.bat".

### Part 1
The "**files**" folder should initially contain at least three txt files: the base dictionary file (*base_dic.txt in the example*), the training file (*train_dic.txt in the example*), and the test file (*test_set.txt in the example*).

What should be emphasized are that: (1) "**base_dic**" is a large (e.g., with size larger than 1 million) and weak password set; (2) It needs to be from the **same language** as "**test_set**". For example, the 31.7 million Tianya dataset can be chosen as the Chinese base_dic, while the 32.6 million Rockyou  dataset can be chosen as the English base_dic,

And "**train_dic**" needs to be as close as possible to the "**test_set**", i.e., **the same language and the same password policy**. Moreover, it's better that the website types are similar, for example, both of them come from social network sites.

Following is the example of contents of the three input files:

391	123456 <br>
276	a123456 <br>
161	5201314 <br>
158	123456a <br>
154	111111 <br>
133	woaini1314 <br>
98	123123 <br>
.......

i.e.,each line looks like "**frequency(integer) \t password(string)**".

### Part 2
To run the program, you need to set the path of four files (i.e., *dictionary file base_dic.txt, training file train_dic.txt, test file test_set.txt, and result file PSM_result.txt*)

For convenience, a script "**run.bat**" is given in this folder. The paths of the four files have been set,i.e., "./files/base_dic.txt", "./files/train_dic.txt", "./files/test_set.txt",  "./files/PSM_result.txt".

Double-click the script file "**run.bat**" to automatically run the program "**fuzzyPSM.exe**" and evaluate "**test_set.txt**" to get the (output) result file "**PSM_result.txt**".

> You can change the path of these four files in the script according to the actual situation.

### Part 3
When the running of the program finishes, the evaluation results will be generated and stored in "**./files/PSM_result.txt**".

Each line is a double floating-point number belonging to [0,1], representing the evaluation result (i.e., the probability of the occurrence of the password) of each password in the test file "test_set.txt".