#ifndef HEXGRID_GLOBAL_H
#define HEXGRID_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HEXGRID_LIBRARY)
#  define HEXGRIDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HEXGRIDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HEXGRID_GLOBAL_H
