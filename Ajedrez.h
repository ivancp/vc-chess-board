// Ajedrez.h: archivo de encabezado principal para la aplicaci�n Ajedrez
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // S�mbolos principales


// CAjedrezApp:
// Consulte la secci�n Ajedrez.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CAjedrezApp : public CWinApp
{
public:
	CAjedrezApp();


// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementaci�n
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAjedrezApp theApp;