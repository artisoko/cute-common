#include "glwindow.h"

#include <QtWidgets>
#include "glwidget.h"
#include "glwindow.h"

namespace artisoko { namespace common {

class Test : public artisoko::common::Drawable {
    void draw() {

        GLfloat faceColor[4] = {0.75f, 0.0, 0.0, 1.0} ;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, faceColor);

        glBegin(GL_TRIANGLES);

        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(0,-1,0);

        glEnd();
    }
};

static Test test ;

GlWindow::GlWindow(Drawable& d)
{
    glWidget = new GLWidget(d);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
    setWindowTitle(tr("Hello,dr. Kartzschevsky"));
}

GlWindow::GlWindow()
{
    glWidget = new GLWidget(test);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
    setWindowTitle(tr("Hello,dr. Kartzschevsky"));

}

void GlWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}


}}
