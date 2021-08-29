/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef GOLDBOX_CALIBRATION_H
#define GOLDBOX_CALIBRATION_H

#include <QObject>
#include <QPointer>
#include "Channel.h"
#include "Table.h"

namespace GoldBox {
class Calibration : public QObject
{
    Q_OBJECT

    enum class ChannelNumbers
    {
        RPM                 = 0x00,
        THROTTLE_POSITION   = 0x01,
        MAP                 = 0x02,
        ENGINE_TEMP         = 0x04,
        LAMBDA_1            = 0x05,
        BAP                 = 0x09,
        FUEL_PRESSURE       = 0x0b,
        BATTERY_VOLTAGE     = 0x3a,
        ECU_INTERNAL_TEMP   = 0x3b,
        LOAD                = 0x45,
        EFFICIENCY          = 0x46,
        EFFICIENCY_2        = 0x47,
        EFFICIENCY_Z        = 0x48
    };

    enum class SensorCalNumbers
    {
        PRES_BAR_3_DEC      = 0x93,
        PRES_INHG_1_DEC     = 0xe8,
        PRES_PSI_1_DEC      = 0xee,
        PRES_KPA_1_DEC      = 0xf4,
        TEMP_DEGF_1_DEC     = 0xfc,
        TEMP_DEGC_1_DEC     = 0xff
    };
    struct E35File
    {
        qint8 unknown1[0x380];
        qint8 bank1trim;
        qint8 bank2trim;
        qint8 unknown2[3234];
        qint8 target_lambda_values[440];
        qint8 unknown3[152];
        qint8 spark_main_values[3850];
        qint8 unknown4[22];
        qint8 injection_timing_values[440];
        qint8 unknown5[440];
        qint8 fuel_main_values[1920];
        qint8 unknown6[439];
        qint8 filename[17]; // may be longer than this
        qint8 unknown7[343];
        qint8 fuel_overall_trim;
        qint8 unkown8[936];
        qint8 fuel_individual_trims[12];
        qint8 unknown9[4357];
        qint8 injector_battery_comp_values[121];
        qint8 unkown10[127];
        qint8 ijpu;
        qint8 unknown11[5437];
        qint8 aim_boost_values[220];
        qint8 unknown12[5697];
        qint8 number_of_cylinders;
        qint8 unknown13[2];
        qint8 load_calc_method;
        qint8 efficiency_calc_method;
        qint8 efficiency_2_calc_method;
        qint8 unknown14[2];
        qint8 fuel_2nd_load_table_mode;
        qint8 unknown15[6461];
        qint8 map_calibration_type;
        qint8 inlet_air_temp_calibration_type;
        qint8 engine_temp_calibration_type;
        qint8 lambda1_calibration_type;
        qint8 lambda2_calibration_type;
        qint8 unknown16[59];
        qint8 map_input_source;
        qint8 unknown17[771];
        qint8 fuel_x_chan_number[2];
        qint8 unknown18[24];
        qint8 injector_timing_x_chan_number[2];
        qint8 unknown19[2];
        qint8 spark_main_x_chan_number[2];
        qint8 unknown19a[4];
        qint8 aim_boost_x_chan_number[2];
        qint8 unknown20[166];
        qint8 target_lambda_x_chan_number[2];
        qint8 unknown21[72];
        qint8 injector_battery_comp_x_chan_number[2];
        qint8 unknown22[520];
        qint8 fuel_y_chan_number[2];
        qint8 unknown23[24];
        qint8 injector_timing_y_chan_number[2];
        qint8 unknown24[2];
        qint8 spark_main_y_chan_number[2];
        qint8 unknown25[4];
        qint8 aim_boost_y_chan_number[2];
        qint8 unknown26[166];
        qint8 target_lambda_y_chan_number[2];
        qint8 unknown27[72];
        qint8 injector_battery_comp_y_chan_number[2];
        qint8 unknown28[620];
        qint8 map_pressure_cal[52];
        qint8 inlet_air_temp_temp_cal[52];
        qint8 engine_temp_temp_cal[52];
        qint8 unknown29[3172];
        qint8 map_voltage_cal[52];
        qint8 unknown30[3172];
        qint8 fuel_main_x_values[80];
        qint8 fuel_main_y_values[48];
        qint8 unknown31[616];
        qint8 injection_timing_x_values[40];
        qint8 injection_timing_y_values[22];
        qint8 unknown32[1654];
        qint8 spark_main_x_values[110];
        qint8 spark_main_y_values[70];
        qint8 unknown33[1862];
        qint8 aim_boost_x_values[40];
        qint8 aim_boost_y_values[22];
        qint8 unknown34[1360];
        qint8 target_lambda_x_values[40];
        qint8 target_lambda_y_values[22];
        qint8 unknown35[2142];
        qint8 injector_battery_comp_x_values[22];
        qint8 injector_battery_comp_y_values[22];
    };
public:
    explicit Calibration();
    explicit Calibration(QByteArray *data);
    ~Calibration();


    Q_PROPERTY(QString comment READ getComment WRITE setComment)
    Q_PROPERTY(QString fileName READ getFilename WRITE setFilename)
    Q_PROPERTY(qint8 fuelOverallTrim READ getFuelOverallTrim WRITE setFuelOverallTrim)
    Q_PROPERTY(QList<Channel *> channels READ getChannels)
    Q_PROPERTY(QList<Table *> tables READ getTables)
private:
    QString m_comment;
    QString m_filename;
    qint8 m_fuelOverallTrim;
    qint16 m_bank1trim;
    qint16 m_bank2trim;

    QString getComment();
    void setComment(QString comment);

    QString getFilename();
    void setFilename(QString filename);

    qint8 getFuelOverallTrim();
    void setFuelOverallTrim(qint8 fuelOverallTrim);

    QList<Channel *> getChannels();
    QList<Table *> getTables();
};
}
#endif // GOLDBOXC_CALIBRATION_H
