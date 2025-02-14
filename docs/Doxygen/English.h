/**
\~english

\defgroup LIBAPI Rabbit remote control library
\brief Rabbit remote control library

\defgroup LIBAPI_SERVICE Service library
\brief Service library
\details Class relationship
\image html docs/Image/PluginServiceAPI.svg
\ingroup LIBAPI

\defgroup LIBAPI_VIEWER Viewer library
\brief Viewer library
\details 
- Viewer plugin interfaces Class relationship
  \image html docs/Image/PluginViewerAPI.svg
\ingroup LIBAPI

\defgroup VIEWER_API Viewer application interface
\brief Viewer application interface
\ingroup LIBAPI_VIEWER

\defgroup VIEWER_PLUGIN_API Viewer plugin interfaces
\ingroup LIBAPI_VIEWER
\brief Viewer plugin interfaces.
\details
+ Class relationship
  \image html docs/Image/PluginViewerAPI.svg
+ Write a plugin:
  - The format of the generated plug-in target name is: PluginViewer${PROJECT_NAME}
    Note: The PROJECT_NAME is same as translation file(.ts) name.
    \include Plugins/TigerVnc/Viewer/CMakeLists.txt
  - Implement CPlugin. For example: \ref CPluginTigerVnc
    - Implement the Qt interface in the class declaration:
      \snippet Plugins/TigerVnc/Viewer/PluginTigerVnc.h Qt plugin interface
    - Initialize the operation in the constructor. For example: initializing resources, loading translation resources, etc.
      \snippet Plugins/TigerVnc/Viewer/PluginTigerVnc.cpp Initialize resorce
    - Release resources in the destructor.
      \snippet Plugins/TigerVnc/Viewer/PluginTigerVnc.cpp Clean resource
    - Implement properties and functions
      - Plugin name: it muse is same as translation file(.ts) name \ref CPluginTigerVnc::Name() 
        \include Plugins/TigerVnc/Viewer/PluginTigerVnc.cpp
  - Implement \ref CConnecter. For example: \ref CConnecterTigerVnc
    - Implement remote desktop, which can be derived from \ref CConnecterDesktop
    - Implement remote console, which can be derived from \ref CConnecterPluginsTerminal
    - If the above two cannot meet your needs, you  can be derived from \ref CConnecter
  -Implement a specific connection, derived from \ref CConnect. For example: \ref CConnectTigerVnc 

*/
