@ECHO OFF

REM set target=i386
set target=amd64

set DDK=C:\WinDDK\7600.16385.1
set MSVC=%DDK%\bin\x86\%target%
set incl=/I"%DDK%\inc\crt" /I"%DDK%\inc\api"
set libs=/LIBPATH:"%DDK%\lib\crt\%target%" /LIBPATH:"%DDK%\lib\wnet\%target%"

set src=%CD%
set C_FLAGS=/W4 /MD /O1 /Os /Oi /GS- /TC
set files=%src%\elements.c %src%\geometry.c %src%\input.c

%MSVC%\cl.exe %incl% %C_FLAGS% %files% /link %libs% opengl32.lib glut32.lib

pause
