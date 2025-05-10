#include "qsynthbuttonpanel.h"
#include "qsynthbuttonpanelplugin.h"

#include <QtPlugin>

QSynthButtonPanelPlugin::QSynthButtonPanelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QSynthButtonPanelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QSynthButtonPanelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QSynthButtonPanelPlugin::createWidget(QWidget *parent)
{
    return new QSynthButtonPanel(parent);
}

QString QSynthButtonPanelPlugin::name() const
{
    return QLatin1String("QSynthButtonPanel");
}

QString QSynthButtonPanelPlugin::group() const
{
    return QLatin1String("");
}

QIcon QSynthButtonPanelPlugin::icon() const
{
    return QIcon();
}

QString QSynthButtonPanelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QSynthButtonPanelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QSynthButtonPanelPlugin::isContainer() const
{
    return false;
}

QString QSynthButtonPanelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QSynthButtonPanel\" name=\"qSynthButtonPanel\">\n</widget>\n");
}

QString QSynthButtonPanelPlugin::includeFile() const
{
    return QLatin1String("qsynthbuttonpanel.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qsynthbuttonpanelplugin, QSynthButtonPanelPlugin)
#endif // QT_VERSION < 0x050000
