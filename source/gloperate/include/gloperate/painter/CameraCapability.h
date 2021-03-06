/******************************************************************************\
 * gloperate
 *
 * Copyright (C) 2014 Computer Graphics Systems Group at the 
 * Hasso-Plattner-Institut (HPI), Potsdam, Germany.
\******************************************************************************/
#pragma once

#include <glm/glm.hpp>
#include <globjects/base/CachedValue.h>

#include <gloperate/gloperate_api.h>

#include <gloperate/painter/AbstractCameraCapability.h>

#include <gloperate/base/Signal.h>

namespace gloperate {

/**
*  @brief
*    Base class for painter camera capabilities
*
*/
class GLOPERATE_API CameraCapability : public AbstractCameraCapability
{


public:
    /**
    *  @brief
    *    Constructor
    */
    CameraCapability(
        const glm::vec3 & eye = glm::vec3(0.0, 0.0, 1.0),
        const glm::vec3 & center = glm::vec3(0.0, 0.0, 0.0),
        const glm::vec3 & up = glm::vec3(0.0, 1.0, 0.0));

    /**
    *  @brief
    *    Destructor
    */
    virtual ~CameraCapability();
    bool autoUpdating() const;
    void setAutoUpdating(bool b);

    virtual const glm::vec3 & eye() const override;
    virtual void setEye(const glm::vec3 & eye) override;
    virtual const glm::vec3 & center() const override;
    virtual void setCenter(const glm::vec3 & center) override;
    virtual const glm::vec3 & up() const override;
    virtual void setUp(const glm::vec3 & up) override;

    // lazy matrices getters
    virtual const glm::mat4 & view() const override;
    virtual const glm::mat4 & viewInverted() const override;

    virtual const glm::mat3 & normal() const override;

    void update() const;

protected:
    void dirty(bool update = true);
    void invalidateMatrices() const;

protected:
    mutable bool m_dirty;
    bool m_autoUpdate;

    glm::vec3 m_eye;
    glm::vec3 m_center;
    glm::vec3 m_up;

    globjects::CachedValue<glm::mat4> m_view;
    globjects::CachedValue<glm::mat4> m_viewInverted;
    globjects::CachedValue<glm::mat3> m_normal;
};


} // namespace gloperate
