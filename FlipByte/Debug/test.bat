@echo off

flipbyte.exe 6 > result.txt
if ERRORLEVEL 1 goto err
fc.exe result.txt answer1.txt

flipbyte.exe 255 > result.txt
if ERRORLEVEL 1 goto err
fc.exe result.txt answer2.txt

flipbyte.exe 0 > result.txt
if ERRORLEVEL 1 goto err
fc.exe result.txt answer3.txt

flipbyte.exe 145 > result.txt
if ERRORLEVEL 1 goto err
fc.exe result.txt answer4.txt

echo Ошибок нет
pause

:err
echo Ошибка программы