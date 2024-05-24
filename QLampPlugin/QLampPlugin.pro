#-------------------------------------------------
#
# Project created by QtCreator 2024-05-24T15:03:55
#
#-------------------------------------------------

QT       += core gui

TARGET = QLampPlugin
TEMPLATE = lib
CONFIG += plugin designer

DESTDIR = $$[QT_INSTALL_PLUGINS]/designer

SOURCES += qlampplugin.cpp \
    qlamp.cpp

HEADERS += qlampplugin.h \
    qlamp.h
symbian {
# Load predefined include paths (e.g. QT_PLUGINS_BASE_DIR) to be used in the pro-files
    load(data_caging_paths)
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE3E684D6
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    pluginDeploy.sources = QLampPlugin.dll
    pluginDeploy.path = $$QT_PLUGINS_BASE_DIR/QLampPlugin
    DEPLOYMENT += pluginDeploy
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
