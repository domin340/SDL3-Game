#include <Engine/time.hpp>

// TIMER
// ------------------------------------------------------------

/// @brief can return 1 if duration is too low or is already playing otherwise 0
/// @return 1 if could not start the timer and 0 if it was successfully done so
int Timer::Play()
{
    if (Duration <= 0 || IsPlaying)
        return 1;

    if (IsDone)
    {
        // play again
        StartTime = SDL_GetTicks();
        IsDone = false;
    }
    else if (!IsPlaying)
    {
        // continue playing
        IsPlaying = true;
    }

    return 0;
}

void Timer::Stop()
{
    IsPlaying = false;
}

// ------------------------------------------------------------

// GAME TIME
// ------------------------------------------------------------

void GameTime::Refresh()
{
    LastUpdate = TotalElapsed;
    TotalElapsed = SDL_GetTicks();
    DeltaTime = (float)(TotalElapsed - LastUpdate) / 1000.0f;

    for (Timer &timer : Timers)
    {
        if (timer.IsDone || !timer.IsPlaying)
            continue;

        timer.Elapsed += DeltaTime;

        if (timer.Elapsed >= timer.Duration / 1000.0f)
        {
            timer.IsDone = true;
        }
    }
}

Timer &GameTime::AddTimer(float duration, const string &ID)
{
    Timer instance = Timer(duration, ID);
    Timers.push_back(instance);
    return Timers.back();
}

Timer &GameTime::AddTimer(float duration)
{
    return GameTime::AddTimer(duration, std::to_string(Timers.size()));
}

/// @brief removes a timer from timers vector
/// @param ID id of a timer
/// @return 1 if timer was not found, 0 if timer was successfully removed
int GameTime::RemoveTimer(const string &ID)
{
    for (int i = 0; i < Timers.size(); i++)
    {
        if (Timers[i].SystemID == ID)
        {
            Timers.erase(Timers.begin() + i);
            return 0;
        }
    }

    return 1;
}

Timer *GameTime::GetTimer(const string &ID)
{
    for (Timer &timer : Timers)
    {
        if (timer.SystemID == ID)
        {
            return &timer;
        }
    }

    return nullptr;
}

// ------------------------------------------------------------
