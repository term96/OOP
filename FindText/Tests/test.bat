@echo off

echo Проверяем поиск в пустом файле
echo Верный результат: "Text not found", результат программы:
findtext.exe empty.txt "key"
pause
cls

echo Проверяем поиск в однострочном файле

echo Верный результат: "Text not found", результат программы:
findtext.exe one-line.txt "cheese"
pause
cls

echo Верный результат: "1", результат программы:
findtext.exe one-line.txt "Try to find me"
pause
cls

echo Проверяем поиск в многострочном файле

echo Верный результат: "Text not found", результат программы:
findtext.exe multiline.txt "food"
pause
cls

echo Верный результат: "1 4", результат программы:
findtext.exe multiline.txt "rok"
pause
cls

echo Верный результат: "3", результат программы:
findtext.exe multiline.txt "Black"
pause