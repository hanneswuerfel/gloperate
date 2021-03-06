/******************************************************************************\
 * gloperate
 *
 * Copyright (C) 2014 Computer Graphics Systems Group at the
 * Hasso-Plattner-Institut (HPI), Potsdam, Germany.
\******************************************************************************/
#include <gloperate-qt/QtKeyEventProvider.h>

#include <gloperate/input/input.h>
#include <gloperate/input/KeyboardEvent.h>

#include <gloperate-qt/QtEventTransformer.h>

using namespace gloperate;

namespace gloperate_qt
{

/**
*  @brief
*    Constructor
*/
QtKeyEventProvider::QtKeyEventProvider()
{
}

/**
*  @brief
*    Destructor
*/
QtKeyEventProvider::~QtKeyEventProvider()
{
}

bool QtKeyEventProvider::eventFilter(QObject * obj, QEvent * event)
{
    if (event->type() == QEvent::KeyPress ||
        event->type() == QEvent::KeyRelease)
    {
        QKeyEvent * qKeyEvent = dynamic_cast<QKeyEvent*>(event);
        if (qKeyEvent) {
            auto eventType = QtEventTransformer::keyboardTypeFromQtType(qKeyEvent->type());
            auto key = QtEventTransformer::fromQtKeyCode(qKeyEvent->key(), qKeyEvent->modifiers());
            KeyboardEvent * keyEvent = new KeyboardEvent(eventType
                , key, qKeyEvent->nativeScanCode(), qKeyEvent->modifiers());
            passEvent(keyEvent);
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

} // namespace gloperate_qt
