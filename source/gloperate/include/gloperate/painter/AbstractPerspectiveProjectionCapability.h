/******************************************************************************\
 * gloperate
 *
 * Copyright (C) 2014 Computer Graphics Systems Group at the 
 * Hasso-Plattner-Institut (HPI), Potsdam, Germany.
\******************************************************************************/
#pragma once

#include <glm/glm.hpp>
#include <gloperate/gloperate_api.h>

#include <gloperate/painter/AbstractProjectionCapability.h>


namespace gloperate {

/**
*  @brief
*    Base class for painter camera capabilities
*
*/
class GLOPERATE_API AbstractPerspectiveProjectionCapability : public AbstractProjectionCapability
{


public:
    /**
    *  @brief
    *    Constructor
    */
    AbstractPerspectiveProjectionCapability(AbstractViewportCapability * viewportCapability);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~AbstractPerspectiveProjectionCapability();

    virtual float zNear() const = 0;
    virtual void setZNear(float zNear) = 0;
    virtual float zFar() const = 0;
    virtual void setZFar(float zFar) = 0;

    virtual float fovy() const = 0;
    virtual void setFovy(float fovy) = 0;

    virtual float aspectRatio() const = 0;

protected:
    virtual void setAspectRatio(float ratio) = 0;
    virtual void setAspectRatio(const glm::ivec2 & viewport) = 0;

    virtual void onViewportChanged();

};


} // namespace gloperate
