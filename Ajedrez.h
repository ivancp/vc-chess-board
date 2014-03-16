// Ajedrez.h: archivo de encabezado principal para la aplicación Ajedrez
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CAjedrezApp:
// Consulte la sección Ajedrez.cpp para obtener información sobre la implementación de esta clase
//

class CAjedrezApp : public CWinApp
{
public:
	CAjedrezApp();


// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAjedrezApp theApp;