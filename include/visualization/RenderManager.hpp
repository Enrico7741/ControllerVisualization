//--------------------------------------------------------------------------------------------------
// Cross-Platform Controller Input Visualization
// Copyright (C) 2021 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef VISUALIZATION_RENDERMANAGER_HPP
#define VISUALIZATION_RENDERMANAGER_HPP

#include "Layout.hpp"

#include <SDL.h>
#include <iostream>

// Predefined elements which can be drawn
struct TextWidget
{
    int xPos;
    int yPos;
    const std::string &text;
    bool highlighted{false};
};

struct PixelWidget
{
    int xPos;
    int yPos;
    int scale;
    bool set{false};
};

struct OutlineWidget
{
    int xPos;
    int yPos;
    int width;
    int height;
};

struct SectionBoxWidget
{
    int xPos;
    int yPos;
    int width;
    int height;
};

class RenderManager
{
public:
    RenderManager(SDL_Renderer *renderer);
    ~RenderManager();

    // Overloaded drawing methodes
    void render(const TextWidget &widget) const;
    void render(const PixelWidget &widget) const;
    void render(const OutlineWidget &widget) const;
    void render(const SectionBoxWidget &widget) const;
    void updateScreen();

private:
    SDL_Renderer *renderer;
    SDL_Texture *font;
    
    void setColor(Layout::Color color) const;
    void renderBackgroundColor();
    void loadBitmap(SDL_Texture **texture, const std::string &path);
};

#endif