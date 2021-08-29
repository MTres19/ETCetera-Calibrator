/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "Channel.h"
using namespace GoldBox;

Channel::Channel(QString name,
                    KUnitConversion::UnitId unit,
                    ValueSize size,
                    qint8 scaling
                 ) : m_name(name), m_unit(unit), m_size(size), m_scaling(scaling)
{

}

KUnitConversion::Value getValue()
{

}

void Channel::setValue(Table *table)
{

}

void Channel::setValue(int value)
{

}
