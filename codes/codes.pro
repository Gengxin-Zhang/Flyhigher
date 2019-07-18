#-------------------------------------------------
#
# Project created by QtCreator 2019-07-17T20:08:27
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Flyhigher
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
CONFIG+= console

ICON = Icon.icns


HEADERS += tools/Vector2D.h \
    main/games/ResourceEntityGenerator.h \
    main/systems/StartThread.h \
            tools/Color.h \
            tools/Point2D.h \
            tools/Logger.h \
 \#            tools/DataReader.h
    ui/uitest.h

SOURCES += tools/Vector2D.cpp \
            main/games/ResourceEntityGenerator.cpp \
    main/systems/StartThread.cpp \
            tools/Color.cpp \
            tools/Point2D.cpp \
            tools/Logger.cpp \
 \#            tools/DataReader.cpp
    ui/uitest.cpp


HEADERS += ui/readonlydelegate.h \
           ui/uiconfig.h

SOURCES += ui/readonlydelegate.cpp \
            ui/uiconfig.cpp


HEADERS += main/configs/Configuration.h \
            main/configs/BomberConfiguration.h \
            main/configs/CarrierConfiguration.h \
            main/configs/FighterConfiguration.h \
            main/configs/PlayerConfiguration.h \
            main/configs/GameConfiguration.h \
            main/configs/JudgerConfiguration.h \
            main/configs/LoopConfiguration.h \
            main/configs/MapConfiguration.h \
            main/configs/NukeConfiguration.h \
            main/configs/PlaneConfiguration.h \
            main/configs/WeaponConfiguration.h \
            main/configs/LittleStarConfiguration.h \
            main/configs/RebuildableConfiguration.h \
            main/configs/LargeStarConfiguration.h

SOURCES += main/configs/Configuration.cpp \
            main/configs/BomberConfiguration.cpp \
            main/configs/CarrierConfiguration.cpp \
            main/configs/FighterConfiguration.cpp \
            main/configs/PlayerConfiguration.cpp \
            main/configs/GameConfiguration.cpp \
            main/configs/JudgerConfiguration.cpp \
            main/configs/LoopConfiguration.cpp \
            main/configs/MapConfiguration.cpp \
            main/configs/NukeConfiguration.cpp \
            main/configs/PlaneConfiguration.cpp \
            main/configs/WeaponConfiguration.cpp \
            main/configs/LittleStarConfiguration.cpp \
            main/configs/RebuildableConfiguration.cpp \
            main/configs/LargeStarConfiguration.cpp


HEADERS += main/games/Player.h \
            main/games/Game.h \
            main/games/Judger.h \
            main/games/Loop.h \
            main/games/Map.h


SOURCES += main/games/Player.cpp \
            main/games/Game.cpp \
            main/games/Judger.cpp \
            main/games/Loop.cpp \
            main/games/Map.cpp


HEADERS += main/systems/Engine.h

SOURCES += main/systems/Engine.cpp


HEADERS += main/games/interfaces/Collector.h \
            main/games/interfaces/Damageable.h


HEADERS += main/games/conceptions/Nuke.h \
            main/games/conceptions/Weapon.h

SOURCES += main/games/conceptions/Nuke.cpp \
            main/games/conceptions/Weapon.cpp


HEADERS += main/games/entitys/Bomber.h \
            main/games/entitys/Bullet.h \
            main/games/entitys/Carrier.h \
            main/games/entitys/Entity.h \
            main/games/entitys/Fighter.h \
            main/games/entitys/LargeStar.h \
            main/games/entitys/LittleStar.h \
            main/games/entitys/LivingEntity.h \
            main/games/entitys/MovableEntity.h \
            main/games/entitys/ResourceEntity.h

SOURCES += main/games/entitys/Bomber.cpp \
            main/games/entitys/Bullet.cpp \
            main/games/entitys/Carrier.cpp \
            main/games/entitys/Entity.cpp \
            main/games/entitys/Fighter.cpp \
            main/games/entitys/LargeStar.cpp \
            main/games/entitys/LittleStar.cpp \
            main/games/entitys/LivingEntity.cpp \
            main/games/entitys/MovableEntity.cpp \
            main/games/entitys/ResourceEntity.cpp


SOURCES += main/Main.cpp


SOURCES += main.cpp


#SOURCES += server/server/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../OpenSource/yaml-cpp/build/release/ -lyaml-cpp.0.6.2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../OpenSource/yaml-cpp/build/debug/ -lyaml-cpp.0.6.2
else:unix: LIBS += -L$$PWD/../OpenSource/yaml-cpp/build/ -lyaml-cpp.0.6.2

INCLUDEPATH += $$PWD/../OpenSource/yaml-cpp/include
DEPENDPATH += $$PWD/../OpenSource/yaml-cpp/build

INCLUDEPATH += $$PWD/../OpenSource/rapidjson/include

FORMS += \
    ui/uiconfig.ui \
    ui/uitest.ui
