@echo off

echo �஢��塞 ���� � ���⮬ 䠩��
echo ���� १����: "Text not found", १���� �ணࠬ��:
findtext.exe empty.txt "key"
pause
cls

echo �஢��塞 ���� � �������筮� 䠩��

echo ���� १����: "Text not found", १���� �ணࠬ��:
findtext.exe one-line.txt "cheese"
pause
cls

echo ���� १����: "1", १���� �ணࠬ��:
findtext.exe one-line.txt "Try to find me"
pause
cls

echo �஢��塞 ���� � ��������筮� 䠩��

echo ���� १����: "Text not found", १���� �ணࠬ��:
findtext.exe multiline.txt "food"
pause
cls

echo ���� १����: "1 4", १���� �ணࠬ��:
findtext.exe multiline.txt "rok"
pause
cls

echo ���� १����: "3", १���� �ணࠬ��:
findtext.exe multiline.txt "Black"
pause