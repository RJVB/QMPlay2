#ifndef QTLEGACYSUPPORT_H

#include <qglobal.h>

#if QT_VERSION >= QT_VERSION_CHECK(5,10,0)

#define QJV QJsonValue
#define QJO QJsonObject
#define QJA QJsonArray
#define QJD QJsonDocument

#define toQJsonArray() toArray()

#else

#include <QMPlay2Lib.hpp>

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>

class QJV;

class QMPLAY2SHAREDLIB_EXPORT QJA
{
public:
    QJA(QJsonArray val)
        : m_arr(val)
    {}

    QJV at(int i) const;
    operator QJsonArray() { return m_arr; }
private:
    QJsonArray m_arr;
};

class QMPLAY2SHAREDLIB_EXPORT QJV
{
public:
    QJV(QJsonValue val)
        : m_val(val)
    {}
    QJV(QJsonValueRef val)
        : m_val(QJsonValue(val))
    {}

    QJV operator[](const QString &key) const { return m_val.toObject()[key]; }
    QJV operator[](QLatin1String key) const { return m_val.toObject()[key]; }
    QJsonArray toQJsonArray() const { return m_val.toArray(); }
    QJA toArray() const { return m_val.toArray(); }
    inline QString toString() const { return m_val.toString(); }
    int toInt(int defaultValue = 0) const { return m_val.toInt(defaultValue); }
    inline bool isObject() const { return m_val.isObject(); }
    QJsonObject toObject() const { return m_val.toObject(); }
private:
    QJsonValue m_val;
};

class QMPLAY2SHAREDLIB_EXPORT QJO
{
public:
    QJO(QJsonObject val)
        : m_obj(val)
    {}

    inline bool isEmpty() const { return m_obj.isEmpty(); }
    QJV operator[](const QString &key) const { return m_obj[key]; }
    QJV operator[](QLatin1String key) const { return m_obj[key]; }
private:
    QJsonObject m_obj;
};

class QMPLAY2SHAREDLIB_EXPORT QJD
{
public:
    QJD(QJsonDocument val)
        : m_doc(val)
    {}

    QJV operator[](const QString &key) const { return m_doc.object()[key]; }
    QJV operator[](QLatin1String key) const { return m_doc.object()[key]; }
private:
    QJsonDocument m_doc;
};

#endif

#define QTLEGACYSUPPORT_H
#endif //QTLEGACYSUPPORT_H
