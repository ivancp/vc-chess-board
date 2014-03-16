// AjedrezDoc.h: interfaz de la clase CAjedrezDoc
//


#pragma once


class CAjedrezDoc : public CDocument
{
protected: // Crear sólo a partir de serialización
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

// Implementación
public:
	virtual ~CAjedrezDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
};


