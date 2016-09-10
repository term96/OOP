@echo off
invert.exe test1.txt > result.txt
fc answer1.txt result.txt
if ERRORLEVEL 1 goto err
echo Ответы совпали
pause
cls

invert.exe test2.txt > result.txt
fc answer2.txt result.txt
if ERRORLEVEL 1 goto err
echo Ответы совпали
pause
exit


:err
echo Ответы не совпали
pause
exit