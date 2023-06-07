#include <qglobal.h>

#if QT_VERSION < QT_VERSION_CHECK(5,10,0)

#include "QtLegacySupport.hpp"

QJV QJA::at(int i) const
{
    return m_arr.at(i);
}

#endif
