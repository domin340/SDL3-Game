g++ .\src\main.cpp `
    .\src\modules\vector2.cpp `
    .\src\game.cpp `
    -o .\bin\game.exe `
    -I .\include `
    -L .\lib `
    -lSDL3

python3 .\copyall.py
