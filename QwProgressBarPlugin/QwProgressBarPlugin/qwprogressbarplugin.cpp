#include "qwprogressbar.h"
#include "qwprogressbarplugin.h"

#include <QtPlugin>

QwProgressBarPlugin::QwProgressBarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QwProgressBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QwProgressBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QwProgressBarPlugin::createWidget(QWidget *parent)
{
    return new QwProgressBar(parent);
}

QString QwProgressBarPlugin::name() const
{
    return QLatin1String("QwProgressBar");
}

QString QwProgressBarPlugin::group() const
{
    return QLatin1String("Custom Widget");
}

QIcon QwProgressBarPlugin::icon() const
{
    return QIcon(QLatin1String(":/QwProgcessBar.ico"));
}

QString QwProgressBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QwProgressBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QwProgressBarPlugin::isContainer() const
{
    return false;
}

QString QwProgressBarPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QwProgressBar\" name=\"qwProgressBar\">\n</widget>\n");
}

QString QwProgressBarPlugin::includeFile() const
{
    return QLatin1String("qwprogressbar.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qwprogressbarplugin, QwProgressBarPlugin)
#endif // QT_VERSION < 0x050000
