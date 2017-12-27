#include "QtSimpleBrowser.h"
#include <QApplication>
#include <QWebEngineSettings>

int main(int argc, char *argv[])
{
    // This lets the web view automatically scale on high-dpi displays
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // After setting this attribute, application code that uses pixmap sizes
    // in layout geometry calculations should typically divide by devicePixelRatio() 
    // to get device-independent layout geometry.
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);
    QtSimpleBrowser browser;
    //QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);

    //QUrl url = commandLineUrlArgument();
    //BrowserWindow *window = w.createWindow();
    //window->currentTab()->setUrl(url);

    browser.show();
    return app.exec();
}
