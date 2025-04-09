// SystemTreePlugin.cpp
#include <CubePlugin.h>
#include <QWidget>
#include <QDebug>

class SystemTreePlugin : public cubepluginapi::CubePlugin {
public:
    SystemTreePlugin() : CubePlugin() {}

    virtual void show() override {
        qDebug() << "SystemTreePlugin show() called - skeleton in place.";
    }
};

CUBEPLUGIN(SystemTreePlugin)
