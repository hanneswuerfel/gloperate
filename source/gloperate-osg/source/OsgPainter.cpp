/******************************************************************************\
 * gloperate
 *
 * Copyright (C) 2014 Computer Graphics Systems Group at the 
 * Hasso-Plattner-Institut (HPI), Potsdam, Germany.
\******************************************************************************/
#include <gloperate-osg/OsgPainter.h>
#include <gloperate/capabilities/ViewportCapability.h>


using namespace gloperate;
namespace gloperate_osg
{


/**
*  @brief
*    Constructor
*/
OsgPainter::OsgPainter(ResourceManager & resourceManager)
: Painter(resourceManager)
, m_viewportCapability(new gloperate::ViewportCapability)
{
    // Register capabilities
    addCapability(m_viewportCapability);
}

/**
*  @brief
*    Destructor
*/
OsgPainter::~OsgPainter()
{
}

/**
*  @brief
*    Get OSG scene
*/
osg::Node * OsgPainter::scene() const
{
	return m_scene;
}

/**
*  @brief
*    Set OSG scene
*/
void OsgPainter::setScene(osg::Node * scene)
{
	m_scene = scene;
    m_viewer->setSceneData(m_scene);
}

void OsgPainter::onInitialize()
{
	// Create OSG viewer
    m_viewer = new osgViewer::Viewer;
    m_embedded = m_viewer->setUpViewerAsEmbeddedInWindow(0, 0, 800, 600);

    // Initialize camera
    m_viewer->getCamera()->setProjectionMatrixAsPerspective(45.0, 1.0, 0.5, 1000);
    m_viewer->getCamera()->setViewMatrix(osg::Matrix::lookAt(osg::Vec3(0, 0, 50), osg::Vec3(0, 0, 0), osg::Vec3(0, 1, 0))); 

    // Initialize viewer
	m_viewer->realize();
}

void OsgPainter::onPaint()
{
    // Send resize-event
    m_embedded->resized(m_viewportCapability->x(), m_viewportCapability->y(), m_viewportCapability->width(), m_viewportCapability->height());

	// Draw OSG scene
	m_viewer->frame();
}


} // namespace gloperate_osg
