// AjedrezDoc.cpp: implementaci�n de la clase CAjedrezDoc
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


// Construcci�n o destrucci�n de CAjedrezDoc

CAjedrezDoc::CAjedrezDoc()
{
	// TODO: agregar aqu� el c�digo de construcci�n �nico

}

CAjedrezDoc::~CAjedrezDoc()
{
}

BOOL CAjedrezDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: agregar aqu� c�digo de reinicio
	// (los documentos SDI volver�n a utilizar este documento)

	return TRUE;
}




// Serializaci�n de CAjedrezDoc

void CAjedrezDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: agregar aqu� el c�digo de almacenamiento
	}
	else
	{
		// TODO: agregar aqu� el c�digo de carga
	}
}


// Diagn�sticos de CAjedrezDoc

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
