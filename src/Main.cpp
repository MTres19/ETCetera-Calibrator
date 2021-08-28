/*
 *  SPDX-FileCopyrightText: 2021 Matthew Trescott <matthewtrescott@gmail.com>
 *  SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include <QApplication>
#include <QCommandLineParser>
#include <KMessageBox>
#include <KAboutData>
#include <KLocalizedString>


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
    
    KGuiItem yesButton("Hello", QString(),
                      "This is a tooltip",
                      "This is a WhatsThis help text.");
    
    return KMessageBox::questionYesNo(0, "Hello World", "Hello", yesButton)
        == KMessageBox::Yes ? EXIT_SUCCESS : EXIT_FAILURE;
}
