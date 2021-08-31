/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_CHANNELSOURCE_ABSTRACTCHANNELSOURCE_H
#define GOLDBOX_CHANNELSOURCE_ABSTRACTCHANNELSOURCE_H

#include <QObject>

namespace GoldBox::ChannelSource
{
    class AbstractChannelSource : QObject
    {
        Q_OBJECT

    public:
        enum class IntSize
        {
            UINT8,
            INT8,
            UINT16,
            INT16
        };

        AbstractChannelSource(IntSize size) : m_size(size) {}

        virtual qint32 getValue() = 0;
        Q_PROPERTY(qint32 value READ getValue)

    private:
        IntSize m_size;
    };
}

#endif // GOLDBOX_CHANNELSOURCE_ABSTRACTCHANNELSOURCE_H