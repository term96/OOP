@echo off
invert.exe test1.txt > result.txt
fc answer1.txt result.txt
if ERRORLEVEL 1 goto err

invert.exe test2.txt > result.txt
fc answer2.txt result.txt
if ERRORLEVEL 1 goto err

echo �訡�� ���
pause
exit


:err
echo �⢥�� �� ᮢ����
pause
exit