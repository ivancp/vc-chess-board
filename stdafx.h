// stdafx.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos del proyecto utilizados frecuentemente,
// pero cambiados rara vez

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Excluir material rara vez utilizado de encabezados de Windows
#endif

// Modificar las siguientes secciones define si su objetivo es una plataforma distinta a las especificadas a continuación.
// Consulte la referencia MSDN para obtener la información más reciente sobre los valores correspondientes a diferentes plataformas.
#ifndef WINVER				// Permitir el uso de características específicas de Windows XP o posterior.
#define WINVER 0x0501		// Cambiar para establecer el valor apropiado para otras versiones de Windows.
#endif

#ifndef _WIN32_WINNT		// Permitir el uso de características específicas de Windows XP o posterior.                   
#define _WIN32_WINNT 0x0501	// Cambiar para establecer el valor apropiado para otras versiones de Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Permitir el uso de características específicas de Windows 98 o posterior.
#define _WIN32_WINDOWS 0x0410 // Cambiar para establecer el valor apropiado para Windows Me o posterior.
#endif

#ifndef _WIN32_IE			// Permitir el uso de características específicas de IE 6.0 o posterior.
#define _WIN32_IE 0x0600	// Cambiar para establecer el valor apropiado para otras versiones de IE.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// Algunos constructores CString serán explícitos

// Desactiva la ocultación de MFC para algunos mensajes de advertencia comunes y, muchas veces, omitidos de forma consciente
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // Componentes principales y estándar de MFC
#include <afxext.h>         // Extensiones de MFC





#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// Compatibilidad MFC para controles comunes de Internet Explorer 4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Compatibilidad MFC para controles comunes de Windows
#endif // _AFX_NO_AFXCMN_SUPPORT









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


