g++ .\src\main.cpp `
    .\src\vector2.cpp `
    .\src\game.cpp `
    .\src\time.cpp `
    -o .\bin\game.exe `
    -I .\include `
    -L .\lib `
    -lSDL3

python3 .\copyall.py
