// AjedrezDoc.h: interfaz de la clase CAjedrezDoc
//


#pragma once


class CAjedrezDoc : public CDocument
{
protected: // Crear s�lo a partir de serializaci�n
	CAjedrezDoc();
	DECLARE_DYNCREATE(CAjedrezDoc)

// Atributos
public:

// Operaciones
public:

// Reemplazos
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementaci�n
public:
	virtual ~CAjedrezDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignaci�n de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
};


