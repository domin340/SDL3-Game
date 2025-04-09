#pragma once

// libraries
#include <string>
using std::string;

#include <SDL3/SDL.h>

// instances
#include "vector2.hpp"
#include "time.hpp"

// MAIN CLASS
// ------------------------------------------------------------

class Game
{
protected:
    string _Title;
    int _Width;
    int _Height;

public:
    SDL_Window *Window;
    SDL_Renderer *Renderer;

    GameTime Time;

    Game(string title, int width, int height)
    {
        _Title = title;
        _Width = width;
        _Height = height;

        Window = nullptr;
        Renderer = nullptr;

        Time = GameTime();
    }

    // BASIC METHODS
    // ------------------------------------------------------------

    void Destroy();
    void Init();
    void Refresh();

    // ------------------------------------------------------------

    // PROPERTY GETTERS
    // ------------------------------------------------------------

    inline string GetTitle() { return _Title; }
    inline Vector2 GetSize() { return Vector2(_Width, _Height); }
    inline int GetWidth() { return _Width; }
    inline int GetHeight() { return _Height; }

    // ------------------------------------------------------------

    // PROPERTY SETTERS
    // ------------------------------------------------------------

    void SetTitle(string title);
    void SetSize(int width, int height);
    inline void SetWidth(int width) { SetSize(width, _Height); }
    inline void SetHeight(int height) { SetSize(_Width, height); }

    // ------------------------------------------------------------
};

// ------------------------------------------------------------
