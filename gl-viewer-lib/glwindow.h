#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QWidget>
#include "drawable.h"
#include "gl-viewer-lib_global.h"

namespace artisoko { namespace common {

class GLWidget;

class GLVIEWERLIBSHARED_EXPORT GlWindow: public QWidget
{
//    Q_OBJECT

public:
    GlWindow(artisoko::common::Drawable& d);
    GlWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private:

    GLWidget *glWidget;
};
}}

#endif // GLWINDOW_H
