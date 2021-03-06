/******************************************************************************\
 * gloperate
 *
 * Copyright (C) 2014 Computer Graphics Systems Group at the 
 * Hasso-Plattner-Institut (HPI), Potsdam, Germany.
\******************************************************************************/
#include <gloperate/painter/TypedRenderTargetCapability.h>


namespace gloperate {


/**
*  @brief
*    Constructor
*/
TypedRenderTargetCapability::TypedRenderTargetCapability()
:AbstractTypedRenderTargetCapability()
{
}

/**
*  @brief
*    Destructor
*/
TypedRenderTargetCapability::~TypedRenderTargetCapability()
{
    m_renderTargets.clear();
}

const RenderTarget & TypedRenderTargetCapability::renderTarget(RenderTargetType type)
{
    return m_renderTargets[type];
}

bool TypedRenderTargetCapability::hasRenderTarget(RenderTargetType type)
{
    return (m_renderTargets.count(type) > 0);
}

void TypedRenderTargetCapability::setRenderTarget(
    RenderTargetType type,
    globjects::ref_ptr<globjects::Framebuffer> framebuffer,
    gl::GLenum attachment,
    gl::GLenum format)
{
    m_renderTargets[type] = RenderTarget(framebuffer, attachment, format);
    setChanged(true);
}

void TypedRenderTargetCapability::resetRenderTarget(RenderTargetType type)
{
    m_renderTargets[type] = RenderTarget();
    setChanged(true);
}

} // namespace gloperate
