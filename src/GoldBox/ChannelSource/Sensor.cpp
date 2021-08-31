/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "AbstractChannelSource.h"
#include "Sensor.h"

using namespace GoldBox::ChannelSource;

Sensor::Sensor() : AbstractChannelSource(AbstractChannelSource::IntSize::INT16)
{

}

qint32 Sensor::getValue()
{

}