#pragma once

#include <SDL3/SDL.h>

#include <vector>
#include <string>
using std::string;

/// TODO: Add repeat property (-1 = inf)
struct Timer
{
    /// @brief Represents the id of a timer
    string SystemID;

    /// @brief Time represented in miliseconds the timer has started
    Uint64 StartTime;

    float Elapsed, Duration;
    bool IsPlaying, IsDone;

    void Stop();
    int Play();

    Timer(float duration, string ID)
    {
        SystemID = ID;
        StartTime = SDL_GetTicks();
        Elapsed = 0;
        Duration = duration;
        IsPlaying = false;
        IsDone = Duration <= 0;
    }
};

class GameTime
{
public:
    /// @brief Properties describing how much has passed since the game started and delta time helpers
    Uint64 TotalElapsed, LastUpdate;
    float DeltaTime;

    /// @brief Stores all created timers
    std::vector<Timer> Timers;

    /// @brief Updates all the internal properties and updates timers
    void Refresh();

    Timer &AddTimer(float duration, const string &ID);
    Timer &AddTimer(float duration);

    int RemoveTimer(const string &ID);
    Timer *GetTimer(const string &ID);

    GameTime()
    {
        TotalElapsed = 0;
        LastUpdate = 0;
        DeltaTime = 0;
    }
};
