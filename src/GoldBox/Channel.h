/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_CHANNEL_H
#define GOLDBOX_CHANNEL_H

#include <QObject>
#include <KUnitConversion/Unit>
#include <KUnitConversion/Value>
#include "Table.h"

namespace GoldBox {
class Table;

class Channel : public QObject
{
    Q_OBJECT

public:
    enum class ValueSize
    {
        UINT8,
        INT8,
        UINT16,
        INT16
    };

    Channel(QString name, KUnitConversion::UnitId unit, ValueSize size, qint8 scaling);

    void setValue(Table *table);
    void setValue(int value);
    KUnitConversion::Value getValue();

    Q_PROPERTY(KUnitConversion::UnitId unit READ getUnit)
    Q_PROPERTY(ValueSize size READ getSize)
    Q_PROPERTY(qint8 scaling READ getScaling)

private:
    /* The name property is stored in the object name */
    KUnitConversion::UnitId m_unit;
    ValueSize m_size;
    qint8 m_scaling;
    int m_value;

    QString getName();
    void setName(QString name);

    KUnitConversion::UnitId getUnit();
    void setUnit(KUnitConversion::UnitId unit);

    ValueSize getSize();

    qint8 getScaling();
};
}

#endif // GOLDBOXC_CHANNEL_H
