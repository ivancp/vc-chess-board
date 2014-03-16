// AjedrezDoc.cpp: implementación de la clase CAjedrezDoc
//

#include "stdafx.h"
#include "Ajedrez.h"

#include "AjedrezDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAjedrezDoc

IMPLEMENT_DYNCREATE(CAjedrezDoc, CDocument)

BEGIN_MESSAGE_MAP(CAjedrezDoc, CDocument)
END_MESSAGE_MAP()


// Construcción o destrucción de CAjedrezDoc

CAjedrezDoc::CAjedrezDoc()
{
	// TODO: agregar aquí el código de construcción único

}

CAjedrezDoc::~CAjedrezDoc()
{
}

BOOL CAjedrezDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: agregar aquí código de reinicio
	// (los documentos SDI volverán a utilizar este documento)

	return TRUE;
}




// Serialización de CAjedrezDoc

void CAjedrezDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: agregar aquí el código de almacenamiento
	}
	else
	{
		// TODO: agregar aquí el código de carga
	}
}


// Diagnósticos de CAjedrezDoc

#ifdef _DEBUG
void CAjedrezDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAjedrezDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Comandos de CAjedrezDoc
