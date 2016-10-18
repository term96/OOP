@echo off

htmldecode.exe < html_test1.txt > out.txt
if ERRORLEVEL 1 goto Err
fc out.txt html_ans1.txt

htmldecode.exe < html_test2.txt > out.txt
if ERRORLEVEL 1 goto Err
fc out.txt html_ans2.txt

pause
exit


Err:
echo Test failed
pause
exit