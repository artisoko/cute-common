#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QWheelEvent>
#include "drawable.h"
#include "gl-viewer-lib_global.h"

namespace artisoko { namespace common {


class GLVIEWERLIBSHARED_EXPORT GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(artisoko::common::Drawable& d, QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void keyPressed(QKeyEvent& e);

protected:

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint lastPos;
//    GLDouble eyex,eyey,eyez,centerx,centery,centerz,upx,upy,upz;

    double leftRightAngle ,upDownAngle,lookDistance;
    artisoko::common::Drawable& drawable;

    int x,y;

};
}}
#endif
