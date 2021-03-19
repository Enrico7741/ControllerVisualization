//--------------------------------------------------------------------------------------------------
// Cross-Platform Controller Input Visualization
// Copyright (C) 2021 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef VISUALIZATION_BACKGROUNDSECTION_HPP
#define VISUALIZATION_BACKGROUNDSECTION_HPP

#include "visualization/sections/ISection.hpp"

class BackgroundSection : public ISection
{
public:
    explicit BackgroundSection(std::shared_ptr<RenderManager> renderManager) : ISection(std::move(renderManager)){};

    // BackgroundSection should be unique and local -- no copy/move operators
    BackgroundSection(const BackgroundSection &) = delete;
    BackgroundSection &operator=(const BackgroundSection &) = delete;
    BackgroundSection(BackgroundSection &&) noexcept = delete;
    BackgroundSection &operator=(BackgroundSection &&) noexcept = delete;

    void redraw() override;

private:
    void renderBackground() const;
};

#endif