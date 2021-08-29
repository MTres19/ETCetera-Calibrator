/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include <QApplication>
#include <QCommandLineParser>
#include <KMessageBox>
#include <KAboutData>
#include <KLocalizedString>

#include "MainWindow.h"


int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("etcetera-calibrator");
    
    KAboutData aboutData(QStringLiteral("etcetera-calibrator"),
                         i18n("ETCetera Calibration Tool"),
                         QStringLiteral("0.1"),
                         i18n("Tuning and DAQ operations for Formula SAE"),
                         KAboutLicense::LGPL,
                         i18n("(C) 2021"),
                         i18n("Work-in-progress"),
                         QStringLiteral("https://www.ltu.edu/formulasae"),
                         QStringLiteral("matthewtrescott@gmail.com"));
    aboutData.addAuthor(i18n("Matt Trescott"), i18n("Developer"),
                        QStringLiteral("matthewtrescott@gmail.com"),
                        QStringLiteral("https://trescott.net"),
                        QStringLiteral("MTres19"));
    KAboutData::setApplicationData(aboutData);
    
    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    MainWindow *window = new MainWindow();
    window->show();

    return app.exec();
}
