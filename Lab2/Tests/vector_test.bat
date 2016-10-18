@echo off

Vector.exe < vector_test1.txt > out.txt
if ERRORLEVEL 1 goto Err
fc out.txt vector_ans1.txt

Vector.exe < vector_test2.txt > out.txt
if ERRORLEVEL 1 goto Err
fc out.txt vector_ans2.txt

pause
exit


Err:
echo Test failed
pause
exit