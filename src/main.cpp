#include <Engine/game.hpp>

int main()
{
    Game *game = new Game("Example Game", 640, 480);
    game->Init();

    // loop
    Timer &t = game->Time.AddTimer(3000);
    t.Play();

    while (true)
    {
        game->Refresh();
        if (t.IsDone)
        {
            SDL_Log("%0.4f\n", t.Elapsed);
            break;
        }
    }

    game->Destroy();
    return 0;
}
