//--------------------------------------------------------------------------------------------------
// Cross-Platform Controller Input Visualization
// Copyright (C) 2021 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <algorithm>

UserInterface::~UserInterface()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool UserInterface::initialize()
{
    if (!initializeWindow())
    {
        return false;
    }

    renderManager = std::make_unique<RenderManager>(renderer);

    // Add all desired sections to the section list
    sections.emplace_back(std::make_unique<InfoSection>(renderManager));

    return true;
}

bool UserInterface::initializeWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        std::cout << "Error: SDL_Init: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create our main window
    window = SDL_CreateWindow("Controller Input Visualization",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              Layout::MainWindow::width, Layout::MainWindow::height,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "Error: SDL_CreateWindow: " << SDL_GetError() << std::endl;
        return false;
    }

    // Try to load the taskbar logo
    auto icon = SDL_LoadBMP("data/bitmaps/windowIcon.bmp");
    if (icon == nullptr)
    {
        std::cout << "Error: SDL_LoadBMP: " << SDL_GetError() << std::endl;
    }
    else
    {
        SDL_SetWindowIcon(window, icon);
        SDL_FreeSurface(icon);
    }

    // Create a renderer for the window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout << "Error: SDL_CreateRenderer: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void UserInterface::run()
{
    startRedrawTimer();
    SDL_Event event;
    auto running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_USEREVENT)
            {
                handleTimerEvent();
            }
            else if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }
}

void UserInterface::startRedrawTimer()
{
    redrawTimerId = SDL_AddTimer(kRedrawInterval, timerCallback, nullptr);
}

void UserInterface::stopTimer(SDL_TimerID timerId)
{
    SDL_RemoveTimer(timerId);
}

void UserInterface::handleTimerEvent()
{
    updateScreen();
    SDL_Delay(10);
}

uint32_t UserInterface::timerCallback(uint32_t interval, void *param)
{
    /**
     * Every time a timer calls this methode an event gets pushed
     * to the event queue of the program so we can handle it.
     */
    SDL_Event event;
    SDL_UserEvent userevent;

    userevent.type = SDL_USEREVENT;
    userevent.code = kRedrawEvent;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return (interval);
}

void UserInterface::updateScreen()
{
    for (const auto &section : sections)
    {
        section->redraw(chip8.getState());
    }
    renderManager->updateScreen();
}