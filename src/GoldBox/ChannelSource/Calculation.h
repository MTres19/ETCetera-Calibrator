/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_CHANNELSOURCE_CALCULATION_H
#define GOLDBOX_CHANNELSOURCE_CALCULATION_H

#include <QObject>
#include "AbstractChannelSource.h"

namespace GoldBox::ChannelSource
{
        class Calculation : AbstractChannelSource
        {
        public:
            Sensor();
        };
}

#endif // GOLDBOX_CHANNELSOURCE_CALCULATION_H