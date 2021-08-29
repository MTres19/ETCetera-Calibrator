/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "Calibration.h"
using namespace GoldBox;

#define LE16READ(out, in, offset) out = in->at(offset) | in->at(offset + 1) << 8

Calibration::Calibration()
{
    (new Channel(QStringLiteral("RPM"), KUnitConversion::RPM, Channel::ValueSize::UINT16, 1))->setParent(this);
    (new Channel(QStringLiteral("Engine Temp"), KUnitConversion::Celsius, Channel::ValueSize::UINT16, 10))->setParent(this);
}

Calibration::Calibration(QByteArray *data) : Calibration()
{
    LE16READ(m_bank1trim, data, 0x17c);
    LE16READ(m_bank2trim, data, 0x17e);

    QPointer<Table> table;
    qint16 chan_number;

    table = findChild<Table *>(QStringLiteral("Target Lambda"), Qt::FindDirectChildrenOnly);
    LE16READ(chan_number, data, 0x8d04);
}

QList<Channel *> Calibration::getChannels()
{
    return findChildren<Channel *>(QString(), Qt::FindDirectChildrenOnly);
}
QList<Table *> Calibration::getTables()
{
    return findChildren<Table *>(QString(), Qt::FindDirectChildrenOnly);
}
