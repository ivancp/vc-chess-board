// AjedrezView.h: interfaz de la clase CAjedrezView
//


#pragma once
#include <vector>


class CAjedrezView : public CView
{
protected: // Crear sólo a partir de serialización
	CAjedrezView();
	DECLARE_DYNCREATE(CAjedrezView)
	std::vector<CString> m_vEtiquetas;

	int m_pCeldas[8][8];

// Atributos
public:
	CAjedrezDoc* GetDocument() const;
	CImageList m_imgPiezas;
	POINT m_celdaSel;
	POINT m_celdaCursor;
	bool m_bFichaSeleccionada;
	bool m_bTurnoBlancas;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementación
public:
	virtual ~CAjedrezView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
public:
	// Dibuja el trablero de ajedrez
	void DibujarTablero(CDC* pDC);
public:
	// Situa todas las piezas en su lugar
	void InicializarTablero(void);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
public:
	void MoverFicha(int x, int y);
	inline bool EsPiezaBlanca(int x, int y)
	{
		return m_pCeldas[y][x] % 2 == 1;
	}

	inline bool EsCeldaNula(int x, int y)
	{
		return m_pCeldas[y][x] == -1;
	}
	bool MoverPeonHacia(int x, int y);
	bool MoverCaballoHacia(int x, int y);
	bool MoverAlfilHacia(int x, int y);
	bool MoverTorreHacia(int x, int y);
	bool MoverReyHacia(int x, int y);
	bool MoverReinaHacia(int x, int y);
	bool EsViaLibre(int x, int y);

public:
	void Mensaje(LPCTSTR sMensaje);
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
public:
	void IntentarMovidaHacia(int x, int y);
public:
	void RealizarMovida(int x, int y);
public:
	void CancelarMovida(void);
};

#ifndef _DEBUG  // Versión de depuración en AjedrezView.cpp
inline CAjedrezDoc* CAjedrezView::GetDocument() const
   { return reinterpret_cast<CAjedrezDoc*>(m_pDocument); }
#endif

