cmake_minimum_required(VERSION 3.19)

project(etcetera_calibrator)

set(QT_MIN_VERSION "5.15.1")
set(KF5_MIN_VERSION "5.85.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core
    Widgets
)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    I18n
    WidgetsAddons
    XmlGui
    UnitConversion
)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

add_executable(etcetera_calibrator
    src/Main.cpp
    src/MainWindow.cpp
    src/GoldBox/Calibration.cpp
    src/GoldBox/Channel.cpp
    src/GoldBox/Table.cpp)
target_link_libraries(etcetera_calibrator
    Qt5::Widgets
    KF5::CoreAddons
    KF5::I18n
    KF5::WidgetsAddons
    KF5::XmlGui
    KF5::UnitConversion
)

install(TARGETS etcetera_calibrator ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
