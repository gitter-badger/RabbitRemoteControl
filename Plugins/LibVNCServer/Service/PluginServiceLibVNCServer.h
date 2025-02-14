#ifndef CPLUGINSERVICELIBVNCSERVER_H
#define CPLUGINSERVICELIBVNCSERVER_H

#include "PluginService.h"
#include <QTranslator>

class CPluginServiceLibVNCServer : public CPluginService
{
    Q_OBJECT
    Q_INTERFACES(CPluginService)

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_PLUGIN_METADATA(IID CPluginService_iid)
#endif
    
public:
    CPluginServiceLibVNCServer(QObject *parent = nullptr);
    virtual ~CPluginServiceLibVNCServer();
    
    // CPluginService interface
public:
    virtual const QString Protol() const override;
    virtual const QString Name() const override;
    virtual const QString Description() const override;
    
protected:
    virtual CService *NewService() override;
};

#endif // CPLUGINSERVICELIBVNCSERVER_H
