@echo off
set "source=%1"

:: Se o primeiro argumento for -o, pegamos o segundo como o arquivo .c
if "%1"=="-o" (
    set "source=%2"
)

if "%source%"=="" (
    echo Erro: Informe o nome do arquivo .c
    echo Exemplo: .\compilar meu_jogo.c
    exit /b 1
)

:: Pega o nome do arquivo sem a extensão .c para o executável
for %%f in ("%source%") do set "name=%%~nf"

:: Configurações do Raylib
set "GCC=C:\raylib\w64devkit\bin\gcc.exe"
set "INCLUDE=C:\raylib\raylib\src"
set "LIB=C:\raylib\raylib\src"
set "FLAGS=-O2 -Wall -Wno-missing-braces"
set "LIBS=-lraylib -lopengl32 -lgdi32 -lwinmm"

:: Adiciona a pasta bin ao PATH temporariamente para o assembler funcionar
set "PATH=C:\raylib\w64devkit\bin;%PATH%"

echo [INFO] Compilando %source% para %name%.exe...

"%GCC%" "%source%" -o "%name%.exe" %FLAGS% -I "%INCLUDE%" -L "%LIB%" %LIBS%

if %errorlevel% equ 0 (
    echo [OK] Compilacao concluida com sucesso!
    echo [INFO] Para rodar: .\%name%.exe
) else (
    echo [ERRO] Falha na compilacao.
)
