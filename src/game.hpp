#pragma once

// libraries
#include <string>
using std::string;

#include <SDL3/SDL.h>

// instances
#include "modules/vector2.hpp"

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

    // SILENT UPDATE
    void Refresh();

    // DELTA HANDLERS
    // TODO: IMPLEMENT CLOCK
    // ------------------------------------------------------------

    Uint64 TotalElapsedTime;
    Uint64 LastUpdateTime;

    inline float GetDeltaTime() { return (float)(TotalElapsedTime - LastUpdateTime) / 1000.0f; }

    // ------------------------------------------------------------

    Game(string title, int width, int height)
    {
        _Title = title;
        _Width = width;
        _Height = height;

        Window = nullptr;
        Renderer = nullptr;

        TotalElapsedTime = 0;
        LastUpdateTime = 0;
    }

    // INIT AND DEINIT
    // ------------------------------------------------------------

    void Destroy();
    void Init();

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
