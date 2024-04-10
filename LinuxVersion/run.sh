#!/usr/bin/env bash
path="./data"
dict_file=Tianya_3w
trainSet=Dodonew_4w
testSet=Dodonew_100w
dict_file_path="${path}/${dict_file}_freq_count.txt"
training_set_path="${path}/${trainSet}_freq_count.txt"
test_set_path="${path}/${testSet}_freq_count.txt"
score_file_path="${path}/PSMscore_trainFile_${trainSet}_testFile_${testSet}_dictFile_${dict_file}.txt"


#计算程序效率
start=$(date +%s)
./fuzzypcfg_all_pw ${dict_file_path} $training_set_path $test_set_path $score_file_path
end=$(date +%s)
runningTime=$(( $end - $start ))

count=`wc -l ${test_set_path} | awk '{print $1}'`
efficiency=`expr $count / $runningTime`
echo "运行时间(ms):"$runningTime
echo "测试口令(个):"${count}
echo "每秒可测试口令数(个/s):"${efficiency}


