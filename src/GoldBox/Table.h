/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_TABLE_H
#define GOLDBOX_TABLE_H

#include <QObject>
#include <QPointer>
#include <KUnitConversion/Value>
#include "Channel.h"

namespace GoldBox {
class Channel;

class Table : public QObject
{
    Q_OBJECT

public:
    explicit Table();

    KUnitConversion::Value getValue();
private:

    // Can't use QSharedPointer here because the channels would get destructed before their parent Calibration
    QPointer<GoldBox::Channel> m_x_channel;
    QPointer<Channel> m_y_channel;
    QVector<int> m_x_values;
    QVector<int> m_y_values;
    QVector<int> m_values;
};
}
#endif // GOLDBOXC_TABLE_H
