#include <Engine/game.hpp>

// INIT AND DEINIT
// ------------------------------------------------------------

void Game::Destroy()
{
    if (Window != nullptr)
        SDL_DestroyWindow(Window);
    if (Window != nullptr)
        SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}

void Game::Init()
{
    // Prepare window
    Window = SDL_CreateWindow(_Title.c_str(), _Width, _Height, SDL_WINDOW_RESIZABLE);

    if (Window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to initialize window: %s", SDL_GetError());
        Destroy();
    }

    // Prepare renderer
    Renderer = SDL_CreateRenderer(Window, NULL);

    if (Renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to create a renderer: %s", SDL_GetError());
        Destroy();
    }
}

// ------------------------------------------------------------

// SILENT UPDATE + DELTA HANDLERS
// ------------------------------------------------------------

/// @brief This method refreshes most of the necessary variables required to run the game
void Game::Refresh()
{
    Time.Refresh();
}

// ------------------------------------------------------------

// PROPERTY SETTERS
// ------------------------------------------------------------

void Game::SetTitle(string title)
{
    if (SDL_SetWindowTitle(Window, title.c_str()))
    {
        // update current title
        _Title = title;
    }
    else
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to change window's title: %s", SDL_GetError());
}

void Game::SetSize(int width, int height)
{
    if (SDL_SetWindowSize(Window, width, height))
    {
        _Width = width;
        _Height = height;
    }
    else
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to change window's size: %s", SDL_GetError());
}

// ------------------------------------------------------------
