@echo off

::the directory of four files
set path=./files/

::the base dictionary set file
set dict_file_path=%path%base_dic.txt

::the train set file
set train_set_path=%path%train_dic.txt

::the test set file
set test_set_path=%path%test_set.txt

::the output(result) file
set socre_file_path=%path%PSM_result.txt

::execute fuzzyPSM.exe
start fuzzyPSM.exe %train_set_path% %test_set_path% %socre_file_path% %dict_file_path%