@echo off
echo Начало тестирования 

crypt crypt in1.txt out.txt 234
if ERRORLEVEL 1 goto Err
crypt decrypt out.txt res.txt 234
if ERRORLEVEL 1 goto Err
fc in1.txt res.txt

crypt crypt in2.txt out.txt 153
if ERRORLEVEL 1 goto Err
crypt decrypt out.txt res.txt 153
if ERRORLEVEL 1 goto Err
fc in2.txt res.txt

echo Тестирование завершено
pause
exit

:err
echo Программа завершилась с ошибкой
exit