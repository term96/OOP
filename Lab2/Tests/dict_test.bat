@echo off
echo Test started

rm dict.txt
rm out.txt

dictionary.exe dict.txt < dict_test1.txt > out.txt
if ERRORLEVEL 1 goto Err
fc dict_ans1.txt out.txt

dictionary.exe dict.txt < dict_test2.txt > out.txt
if ERRORLEVEL 1 goto Err
fc dict_ans2.txt out.txt

pause
exit

Err:
echo Test failed
pause
exit