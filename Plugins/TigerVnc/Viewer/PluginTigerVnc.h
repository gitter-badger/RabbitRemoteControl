// Author: Kang Lin <kl222@126.com>

#ifndef CPLUGINTIGERVNC_H_KL_2021_07_23
#define CPLUGINTIGERVNC_H_KL_2021_07_23

#pragma once

#include "PluginViewer.h"
#include <QTranslator>
#include "PluginThread.h"

class CPluginTigerVnc : public CPluginViewer
{
    Q_OBJECT
    
    /// ![Qt plugin interface]
    Q_INTERFACES(CPluginViewer)

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_PLUGIN_METADATA(IID CPluginViewer_iid)
#endif
    /// ![Qt plugin interface]
    
public:
    explicit CPluginTigerVnc(QObject *parent = nullptr);
    virtual ~CPluginTigerVnc() override;
    
    virtual const QString Name() const override;
    virtual const QString Description() const override;
    virtual const QString Protol() const override;
    virtual const QIcon Icon() const override;
    virtual CConnecter* CreateConnecter(const QString& szProtol) override;
    
private:
    CPluginThread* m_pThread;
};

#endif // CPLUGINTIGERVNC_H_KL_2021_07_23
