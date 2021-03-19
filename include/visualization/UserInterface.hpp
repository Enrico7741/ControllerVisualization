//--------------------------------------------------------------------------------------------------
// Cross-Platform Controller Input Visualization
// Copyright (C) 2021 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef VISUALIZATION_USERINTERFACE_HPP
#define VISUALIZATION_USERINTERFACE_HPP

#include "visualization/RenderManager.hpp"
#include "visualization/sections/ISection.hpp"

#include <SDL.h>
#include <memory>
#include <vector>
#include <cstdint>

class UserInterface
{
public:
    //UserInterface(Chip8 &chip8) : chip8{chip8} {};
    ~UserInterface();
    bool initialize();
    void run();

private:
    //Chip8 &chip8;
    SDL_Window *window;
    SDL_Renderer *renderer;

    std::shared_ptr<RenderManager> renderManager{};
    std::vector<std::unique_ptr<ISection>> sections{};

    SDL_TimerID redrawTimerId;
    static const int kRedrawEvent{0};
    static const int kRedrawInterval{17};

    bool initializeWindow();
    void startRedrawTimer();
    void stopTimer(SDL_TimerID timerId);
    void handleTimerEvent();
    static uint32_t timerCallback(uint32_t interval, void *param);
    void updateScreen();
};

#endif