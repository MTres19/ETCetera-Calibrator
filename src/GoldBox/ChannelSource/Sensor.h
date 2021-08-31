/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_CHANNELSOURCE_SENSOR_H
#define GOLDBOX_CHANNELSOURCE_SENSOR_H

#include <QObject>
#include "AbstractChannelSource.h"
#include "Table.h"

namespace GoldBox::ChannelSource
{
    class Sensor : ::GoldBox::ChannelSource::Table
    {
    public:
        Sensor();
        qint32 getValue();

        enum class HardwareInput
        {
            A_TEMP_1,
            A_TEMP_2,
            A_TEMP_3,
            A_TEMP_4,
            A_TEMP_5,
            A_TEMP_6,
            A_VOLT_1,
            A_VOLT_2,
            A_VOLT_3,
            A_VOLT_4,
            A_VOLT_5,
            A_VOLT_6,
            A_VOLT_7,
            A_VOLT_8,
            A_LAMBDA_1,
            A_LAMBDA_2,
            D_SPEED_1,
            D_SPEED_2,
            D_SPEED_3,
            D_SPEED_4,
            // More here, too lazy to enter them all
            SPECIAL_REFSYNC
        };

        enum class CalPreset
        {
            TEMP_C_BOSCH_2500OHM,
            TEMP_C_DELCO_3300OHM,
            TEMP_C_BOSCH_HISPEED,
            // More here, too lazy to enter them all
            TEMP_C_CUSTOM,
            TEMP_F_CUSTOM,
            PRES_PSI_CUSTOM,
            PRES_KPA_CUSTOM,
            PRES_BAR_CUSTOM,
        };
    private:
        qint16 m_value;


        HardwareInput m_input;
        qint16 m_default_value;
        //qint8 m_filter_number;
        qint16 m_diag_low_volts;
        qint16 m_diag_high_volts;
        qint16 m_warn_low_units;
        qint16 m_warn_high_units;
    };
}

#endif // GOLDBOX_CHANNELSOURCE_SENSOR_H