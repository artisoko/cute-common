#include <QtWidgets>
#include <QtOpenGL>

#include <math.h>

#include "glwidget.h"
#include <iostream>
#include <gl/glu.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

namespace artisoko { namespace common {


static QColor qtGreen = QColor::fromCmykF(0.40, 0.0, 1.0, 0.0);
static QColor qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);

GLWidget::GLWidget(Drawable &d, QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
      leftRightAngle(0.0),
      upDownAngle(1.0),
      lookDistance(3.0),
      drawable(d)
{
}

GLWidget::~GLWidget()
{
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::initializeGL()
{
    qglClearColor(qtPurple.dark());

    glEnable(GL_DEPTH_TEST);
    //    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0, 0, 100, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // z - do góry (dodatni)
//    GLdouble x = lookDistance * sin(upDownAngle) * cos(leftRightAngle);
//    GLdouble y = lookDistance * sin(upDownAngle) * sin(leftRightAngle);
//    GLdouble z = lookDistance * cos(leftRightAngle);

//    QVector3D up = QVector3D (0,0,1);

//    gluLookAt(x,y,z,0,0,0,0,0,1);
    glRotatef(90.f, 1,0,0); // patrze na -y
    glTranslatef(0,-lookDistance,0);

    glRotatef(M_PI * 2 * upDownAngle,1.f,0,0 );
    glRotatef(M_PI * 2 * leftRightAngle,0,0,1.f);
//    glRotatef(30.f, 1.0f,0,0);
//    glRotatef(30.f, 0,0,1.0f);

    drawable.draw();
}

static int ODL = 1;

void GLWidget::resizeGL(int width, int height)
{
    //    int side = qMin(width, height);
    glViewport(0,0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.f, 1.f, 0.1, 1000.0);

//#ifdef QT_OPENGL_ES_1
//    glFrustum (-ODL, +ODL, -ODL, +ODL, 0.1, 1000.0);
//#else
//    glFrustum(-ODL, +ODL, -ODL, +ODL, 0.1, 1000.0);
//#endif
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        leftRightAngle += 0.3* dx ;
        upDownAngle += 0.3*dy ;

        updateGL();
    } else if (event->buttons() & Qt::RightButton) {
        lookDistance += (dy+dx) * 0.1 ;
        if (lookDistance < 1) lookDistance = 1 ;
        if (lookDistance > 50) lookDistance = 50 ;
        updateGL();
    }
    lastPos = event->pos();
}

}}
