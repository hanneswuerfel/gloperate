#include <gloperate/tools/ObjectIdExtractor.h>

#include <glm/common.hpp>

namespace gloperate
{

ObjectIdExtractor::ObjectIdExtractor(
    AbstractViewportCapability * viewportCapability,
    AbstractTypedRenderTargetCapability * typedRenderTargetCapability)
:   GBufferExtractor(viewportCapability, typedRenderTargetCapability, RenderTargetType::ObjectID, glm::vec4(0.0))
{
}

ObjectIdExtractor::~ObjectIdExtractor()
{
}

int ObjectIdExtractor::get(const glm::ivec2 & windowCoordinates) const
{
    return static_cast<int>(glm::floor(GBufferExtractor::get(windowCoordinates).x + 0.5));
}

} // namespace gloperate
