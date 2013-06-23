#ifndef HEXGRID_H
#define HEXGRID_H

#include "hexgrid_global.h"

namespace artisoko {
namespace grid {

class HEXGRIDSHARED_EXPORT HexGrid
{
    int width, height;

public:
    virtual void draw() ;
    HexGrid(int w, int h) : width(w), height(h) { }

};
}}

#endif // HEXGRID_H

