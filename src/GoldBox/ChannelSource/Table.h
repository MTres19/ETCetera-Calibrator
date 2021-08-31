/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_CHANNELSOURCE_TABLE_H
#define GOLDBOX_CHANNELSOURCE_TABLE_H

#include <QObject>
#include "AbstractChannelSource.h"

namespace GoldBox::ChannelSource
{
        class Table : AbstractChannelSource
        {
        public:
            Table(int rows, int columns, AbstractChannelSource::IntSize size);
            ~Table();

        private:
            
        };
}

#endif // GOLDBOX_CHANNELSOURCE_TABLE_H