# QtTests.pro

QT += core gui widgets multimedia network testlib

TARGET = QtTests
TEMPLATE = app

SOURCES += main.cpp

# Add resources (images, audio files)
RESOURCES += resources.qrc

# Additional libraries (e.g., SSL support)
#LIBS += -lQt6Network

# Set project configurations for testing
CONFIG += testlib