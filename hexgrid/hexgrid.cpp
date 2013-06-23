#include "hexgrid.h"
#include <qopengl.h>
#include <QColor>
#include <QVector2D>
#include <QMatrix>

namespace artisoko {
namespace grid {


static inline void qSetColor(float colorVec[], QColor c)
{
    colorVec[0] = c.redF();
    colorVec[1] = c.greenF();
    colorVec[2] = c.blueF();
    colorVec[3] = c.alphaF();
}


static void rotate(QVector2D& vec, const QMatrix& mat) {
    float x = vec.x() * mat.m11() + vec.y() * mat.m12();
    float y = vec.x() * mat.m21() + vec.y() * mat.m22();
    vec.setX(x);
    vec.setY(y);
}

void HexGrid::draw()
{
    // glMultMatrixf(mat.constData());
    float d = 1;
    float h = sqrt(3.0f);
    QMatrix mat ;
    mat.rotate(60);


    for (int i=0; i<width;++i)
        for (int j=0; j<height; ++j)
        {
            glBegin(GL_TRIANGLE_FAN);

            GLfloat faceColor[4];

            QColor c = QColor(127,127,127) ;

            if (i % 3 == 0) c.setRed(0);  else if (i % 3 == 2) c.setRed(255);
            if (j % 3 == 0) c.setBlue(0);  else if (j % 3 == 2) c.setBlue(255);

            qSetColor(faceColor, c );
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, faceColor);

            float x = 1.5f * d * i;
            float y = h * j + 0.5f * h * i;

            glVertex3f(0, x,y);
            QVector2D v(d, 0) ;

            for (int k=0; k<7; ++k){
                x += v.x();
                y += v.y();
                glVertex3f(0, x  , y );
                rotate(v,mat);
            }
            glEnd();
        }

}

}}
