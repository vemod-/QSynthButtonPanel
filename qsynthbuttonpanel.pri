!contains(PROFILES,$$_FILE_){
PROFILES+=$$_FILE_

include(../ToggleButton/QToggleButton.pri)

INCLUDEPATH += $$PWD

HEADERS += $$PWD/qsynthbuttonpanel.h
SOURCES += $$PWD/qsynthbuttonpanel.cpp

FORMS += \
    $$PWD/qsynthbuttonpanel.ui

RESOURCES += \
    $$PWD/synthbuttonpanelresources.qrc

}
