//--------------------------------------------------------------------------------------------------
// Cross-Platform Controller Input Visualization
// Copyright (C) 2021 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef VISUALIZATION_SECTIONS_ISECTION_HPP
#define VISUALIZATION_SECTIONS_ISECTION_HPP

#include "visualization/RenderManager.hpp"

#include <memory>

/**
 * Interface for Sections.
 * A section constitutes an isolated region of the user interface.
 * Sections must be able to draw themselves via choosing the relevant state from
 * the controller state itself and then calling methods on the RenderManager
 */
class ISection
{
public:
    // Virtual destructor
    virtual ~ISection() = default;

    // Use the renderManager to redraw the section with a new state
    virtual void redraw(const Chip8State &state) = 0;

protected:
    /**
     * Constructors and assignment operators
     * Protected to allow usage only in inheriting classes
     */
    explicit ISection(std::shared_ptr<RenderManager> renderManager) : renderManager{std::move(renderManager)}{};
    ISection() = default;
    ISection(const ISection &) = default;
    ISection &operator=(const ISection &) = default;
    ISection(ISection &&) noexcept = default;
    ISection &operator=(ISection &&) noexcept = default;

    // Manager to use for rendering on screen
    std::shared_ptr<RenderManager> renderManager{};
};

#endif