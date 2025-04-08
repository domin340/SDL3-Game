#include "game.hpp"

int main()
{
    Game *game = new Game("Example Game", 640, 480);
    game->Init();

    // loop
    float elapsed = 0;
    while (true)
    {
        game->Refresh();
        float dt = game->GetDeltaTime();
        elapsed += dt;
        SDL_Log("%.12f", dt);
        if (elapsed >= 3)
        {
            SDL_Log("%0.4f", elapsed);
            break;
        }
    }

    game->Destroy();
    return 0;
}
