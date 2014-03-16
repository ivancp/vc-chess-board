// AjedrezView.cpp: implementación de la clase CAjedrezView
//

#include "stdafx.h"
#include "Ajedrez.h"

#include "AjedrezDoc.h"
#include "AjedrezView.h"
#include "memdc.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define VACIO -1
#define PEONB 11
#define PEONN 10
#define ALFILB 7
#define ALFILN 6
#define CABALLOB 9
#define CABALLON 8
#define REYB 1
#define REYN 0
#define REINAB 3
#define REINAN 2
#define TORREB 5
#define TORREN 4

#define MARGEN 30
#define TAMCELDA 60
#define CELDAS  8

IMPLEMENT_DYNCREATE(CAjedrezView, CView)

BEGIN_MESSAGE_MAP(CAjedrezView, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Construcción o destrucción de CAjedrezView

CAjedrezView::CAjedrezView()
{
	// TODO: agregar aquí el código de construcción
	m_imgPiezas.Create(IDB_PIEZAS,TAMCELDA,0,RGB(255,0,255));


	//Inicializacion de etiquetas del tablero
	m_vEtiquetas.push_back("8");
	m_vEtiquetas.push_back("7");
	m_vEtiquetas.push_back("6");
	m_vEtiquetas.push_back("5");
	m_vEtiquetas.push_back("4");
	m_vEtiquetas.push_back("3");
	m_vEtiquetas.push_back("2");
	m_vEtiquetas.push_back("1");
	m_vEtiquetas.push_back("a");
	m_vEtiquetas.push_back("b");
	m_vEtiquetas.push_back("c");
	m_vEtiquetas.push_back("d");
	m_vEtiquetas.push_back("e");
	m_vEtiquetas.push_back("f");
	m_vEtiquetas.push_back("g");
	m_vEtiquetas.push_back("h");

	InicializarTablero();
}

CAjedrezView::~CAjedrezView()
{
	m_imgPiezas.DeleteImageList();
}

BOOL CAjedrezView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CAjedrezView

void CAjedrezView::OnDraw(CDC* pDC)
{
	CAjedrezDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMemDC memdc(pDC);
	DibujarTablero(&memdc);

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Diagnósticos de CAjedrezView

#ifdef _DEBUG
void CAjedrezView::AssertValid() const
{
	CView::AssertValid();
}

void CAjedrezView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAjedrezDoc* CAjedrezView::GetDocument() const // La versión de no depuración es en línea
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAjedrezDoc)));
	return (CAjedrezDoc*)m_pDocument;
}
#endif //_DEBUG


// Dibuja el trablero de ajedrez

void CAjedrezView::DibujarTablero(CDC* pDC)
{
	//Definición de colores y fondos
	RECT rcCelda;
	CBrush brNegro,brSeleccion;
	brNegro.CreateSolidBrush(0xf36d4d);
	brSeleccion.CreateSolidBrush(RGB(255,240,108));

	CPen penAzulMarino,penAmarillo;
	penAzulMarino.CreatePen(PS_SOLID,3,0x00640000);
	penAmarillo.CreatePen(PS_SOLID,4,0x0000EEEE);

	CPen *penAnterior = pDC->SelectObject(&penAzulMarino);
	pDC->SetBkMode(TRANSPARENT);
	for(int i = 0 ; i < CELDAS ; i++)
	{
		for(int j = 0 ; j < CELDAS ; j++)
		{
			rcCelda.left  = j*TAMCELDA + MARGEN;
			rcCelda.top   = i*TAMCELDA + MARGEN;  
			rcCelda.right = rcCelda.left + TAMCELDA;
			rcCelda.bottom = rcCelda.top + TAMCELDA;

			if( i%2 == 0 )
			{
				if(j%2 != 0)
				{
						CBrush *pFondoAnterior = pDC->SelectObject(&brNegro);
						pDC->Rectangle(&rcCelda);
						pDC->SelectObject(pFondoAnterior);
				}
				else
				{
					pDC->Rectangle(&rcCelda);
				}
			}
			else
			{
				if(j%2 == 0)
				{
						CBrush *pFondoAnterior = pDC->SelectObject(&brNegro);
						pDC->Rectangle(&rcCelda);
						pDC->SelectObject(pFondoAnterior);
				}
				else
				{
					pDC->Rectangle(&rcCelda);
				}
			}

			if(m_celdaSel.x == j && m_celdaSel.y == i)
			{
				CBrush *pFondoAnterior = pDC->SelectObject(&brSeleccion);
				pDC->Rectangle(&rcCelda);
				pDC->SelectObject(pFondoAnterior);
			}

			if(m_pCeldas[i][j] >= 0)
			{
				POINT p;
				p.x = rcCelda.left;
				p.y = rcCelda.top;
				SIZE s;
				s.cx = s.cy = 60;

				m_imgPiezas.DrawEx(pDC,m_pCeldas[i][j],p,s,RGB(255,0,255),0,ILD_TRANSPARENT);
			}

			//Dibujando las etiquetas
			if(j == 0 || j == 7)
			{
				rcCelda.left  = j==0?MARGEN-15:rcCelda.right;
				rcCelda.right = j==0?MARGEN:rcCelda.right + 15;
				pDC->DrawText(m_vEtiquetas[i],&rcCelda,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
				
				//Restaurando valores para que no 
				//afecte el pintado de las etiquetas verticales
				rcCelda.left  = j*TAMCELDA + MARGEN;
				rcCelda.right = rcCelda.left + TAMCELDA;
			}
			if(i == 0 || i == 7)
			{
				rcCelda.top    = i==0?MARGEN-20:rcCelda.bottom;
				rcCelda.bottom = i==0?MARGEN:rcCelda.bottom + 20;
				pDC->DrawText(m_vEtiquetas[j+8],&rcCelda,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			}

		}
	}
	if(m_celdaCursor.x >= 0 && m_celdaCursor.y >= 0)
	{
		rcCelda.left  = m_celdaCursor.x*TAMCELDA + MARGEN;
		rcCelda.top   = m_celdaCursor.y*TAMCELDA + MARGEN;  
		rcCelda.right = rcCelda.left + TAMCELDA;
		rcCelda.bottom = rcCelda.top + TAMCELDA;

		CPen *pAnterior = pDC->SelectObject(&penAmarillo);
		pDC->MoveTo(rcCelda.left,rcCelda.top);
		pDC->LineTo(rcCelda.right,rcCelda.top);
		pDC->LineTo(rcCelda.right,rcCelda.bottom);
		pDC->LineTo(rcCelda.left,rcCelda.bottom);
		pDC->LineTo(rcCelda.left,rcCelda.top);
		pDC->SelectObject(pAnterior);
	}
	pDC->SelectObject(penAnterior);
}

// Situa todas las piezas en su lugar
void CAjedrezView::InicializarTablero(void)
{
	m_bTurnoBlancas = true;

	m_celdaSel.x = -1;
	m_celdaSel.y = -1;

	m_celdaCursor.x = -1;
	m_celdaCursor.y = -1;

	m_bFichaSeleccionada = false;
	
	//Inicializacion de celdas
	for(int i = 0 ; i < 8 ;i++)
		for(int j = 0 ; j < 8 ; j++)
			m_pCeldas[i][j] = VACIO;

	m_pCeldas[0][0] = TORREN;
	m_pCeldas[0][1] = CABALLON;
	m_pCeldas[0][2] = ALFILN;
	m_pCeldas[0][3] = REINAN;
	m_pCeldas[0][4] = REYN;
	m_pCeldas[0][5] = ALFILN;
	m_pCeldas[0][6] = CABALLON;
	m_pCeldas[0][7] = TORREN;

	m_pCeldas[7][0] = TORREB;
	m_pCeldas[7][1] = CABALLOB;
	m_pCeldas[7][2] = ALFILB;
	m_pCeldas[7][3] = REINAB;
	m_pCeldas[7][4] = REYB;
	m_pCeldas[7][5] = ALFILB;
	m_pCeldas[7][6] = CABALLOB;
	m_pCeldas[7][7] = TORREB;

	m_pCeldas[1][0] = PEONN;
	m_pCeldas[1][1] = PEONN;
	m_pCeldas[1][2] = PEONN;
	m_pCeldas[1][3] = PEONN;
	m_pCeldas[1][4] = PEONN;
	m_pCeldas[1][5] = PEONN;
	m_pCeldas[1][6] = PEONN;
	m_pCeldas[1][7] = PEONN;

	m_pCeldas[6][0] = PEONB;
	m_pCeldas[6][1] = PEONB;
	m_pCeldas[6][2] = PEONB;
	m_pCeldas[6][3] = PEONB;
	m_pCeldas[6][4] = PEONB;
	m_pCeldas[6][5] = PEONB;
	m_pCeldas[6][6] = PEONB;
	m_pCeldas[6][7] = PEONB;
}

void CAjedrezView::OnMouseMove(UINT nFlags, CPoint point)
{
	static int x = -1;
	static int y = -1;

	x = (point.x - MARGEN)/60; 
	y = (point.y - MARGEN)/60;

	if(x >= 0 && y >= 0 && x<8 && y<8)
	{
		if(x != m_celdaCursor.x || y != m_celdaCursor.y )
		{
			m_celdaCursor.x = x;
			m_celdaCursor.y = y;

			Invalidate();
		}
	}
	else
	{
		x=-1;
		y=-1;
		if(x != m_celdaCursor.x || y != m_celdaCursor.y )
		{
			m_celdaCursor.x = -1;
			m_celdaCursor.y = -1;

			Invalidate();
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CAjedrezView::OnLButtonDown(UINT nFlags, CPoint point)
{
	static int x = -1;
	static int y = -1;

	x = (point.x - MARGEN)/60; 
	y = (point.y - MARGEN)/60;

	if(x >= 0 && y >= 0 && x<8 && y<8)
	{
		MoverFicha(x,y);
	}
	CView::OnLButtonDown(nFlags, point);
}

BOOL CAjedrezView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	return FALSE;
}


void CAjedrezView::MoverFicha(int x,int y)
{
	//m_pCeldas[y][x] % 2 = 0  => NEGRAS  (par)
	//m_pCeldas[y][x] % 2 = 1  => BLANCAS (impar)

	if(m_bFichaSeleccionada)
	{
		if(EsCeldaNula(x,y) 
			|| (!EsPiezaBlanca(x,y) && m_bTurnoBlancas)
			|| (EsPiezaBlanca(x,y) && !m_bTurnoBlancas))
		{
			IntentarMovidaHacia(x,y);
		}
		else
		{
			Mensaje("Movida no permitida");
			CancelarMovida();
		}
	}
	else
	{
		if(EsCeldaNula(x,y))
			return;
		if((EsPiezaBlanca(x,y) && m_bTurnoBlancas )
			|| (!EsPiezaBlanca(x,y) && !m_bTurnoBlancas))
		{
			m_celdaSel.x = x;
			m_celdaSel.y = y;
			m_bFichaSeleccionada = true;
			
			Mensaje("Presione ESC para cancelar la selección");

			Invalidate();
		}
	}
}

void CAjedrezView::Mensaje(LPCTSTR sMensaje)
{
	((CMainFrame*)AfxGetMainWnd())->Mensaje(sMensaje);
}

void CAjedrezView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(m_bFichaSeleccionada && nChar == VK_ESCAPE )
	{
			m_celdaSel.x = m_celdaSel.y = -1;
			m_bFichaSeleccionada = false;
			Mensaje("Movida cancelada, continue jugando");
			Invalidate();
			return;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CAjedrezView::IntentarMovidaHacia(int x, int y)
{
	int nPiezaActual = m_pCeldas[m_celdaSel.y][m_celdaSel.x];
	bool bSePuedeMover = false;
	switch(nPiezaActual)
	{
		case PEONB:
		case PEONN:
			bSePuedeMover = MoverPeonHacia(x,y);
			break;
		case ALFILB:
		case ALFILN:
			bSePuedeMover = MoverAlfilHacia(x,y);
			break;
		case CABALLOB:
		case CABALLON:
			bSePuedeMover = MoverCaballoHacia(x,y);
			break;
		case REYB:
		case REYN:
			bSePuedeMover = MoverReyHacia(x,y);
			break;
		case REINAB:
		case REINAN:
			bSePuedeMover = MoverReinaHacia(x,y);
			break;
		case TORREB:
		case TORREN:
			bSePuedeMover = MoverTorreHacia(x,y);
			break;
	}

	if(bSePuedeMover)
	{
		Mensaje("Movida correcta, siguiente jugador");
		RealizarMovida(x, y);
	}
	else
	{
		Mensaje("Movida incorrecta, intenta nuevamente");
		CancelarMovida();
	}
}

bool CAjedrezView::MoverPeonHacia(int x, int y)
{
	int dify = y - m_celdaSel.y;
	int difx = x - m_celdaSel.x;

	bool bMovidaPosible = false;

	if(difx == 0) //Movida Vertical
	{		
		if(abs(dify) == 1)//Si mueve un casillero
		{
			if(dify == (EsPiezaBlanca(m_celdaSel.x ,m_celdaSel.y)?-1:1))
			{
				if(EsCeldaNula(x,y))
					bMovidaPosible = true;
			}
		}
		else if(abs(dify) == 2) //Movida larga de peon
		{
			if(m_celdaSel.y == (EsPiezaBlanca(m_celdaSel.x ,m_celdaSel.y)?6:1))
			{
				if(EsViaLibre(x,y) && EsCeldaNula(x,y))
					bMovidaPosible = true;
			}
		}
	}
	else if((abs(difx) == 1) // Si esta intentando comer
		&& (dify == (EsPiezaBlanca(m_celdaSel.x ,m_celdaSel.y)?-1:1))
		&& !EsCeldaNula(x,y) 
		&& (m_pCeldas[m_celdaSel.y ][m_celdaSel.x] != m_pCeldas[y][x]))
	{
		bMovidaPosible = true;
	}

	return bMovidaPosible;
}
bool CAjedrezView::MoverCaballoHacia(int x, int y)
{
	int dify = y - m_celdaSel.y;
	int difx = x - m_celdaSel.x;

	if(((abs(difx) == 2) && (abs(dify) == 1))||((abs(difx) == 1) && (abs(dify) == 2)))
	{
		if(m_pCeldas[m_celdaSel.y ][m_celdaSel.x] != m_pCeldas[y][x])
		{
			return true;
		}
	}
	return false;
}
bool CAjedrezView::MoverAlfilHacia(int x, int y)
{
	int dify = y - m_celdaSel.y;
	int difx = x - m_celdaSel.x;

	if(abs(difx) == abs(dify))
	{
		if(EsViaLibre(x,y) && m_pCeldas[m_celdaSel.y ][m_celdaSel.x] != m_pCeldas[y][x])
		{			
			return true;
		}
	}
	return false;
}

bool CAjedrezView::MoverTorreHacia(int x, int y)
{ 
	int dify = y - m_celdaSel.y;
	int difx = x - m_celdaSel.x;

	if((difx == 0) || (dify == 0) )
	{
		if(EsViaLibre(x,y) && m_pCeldas[m_celdaSel.y ][m_celdaSel.x] != m_pCeldas[y][x])
		{			
			return true;
		}
	}
	return false;
}
bool CAjedrezView::MoverReyHacia(int x, int y)
{
	int dify = y - m_celdaSel.y;
	int difx = x - m_celdaSel.x;

	if((abs(difx) == 1) || (abs(dify) == 1) )
	{		
		if(m_pCeldas[m_celdaSel.y ][m_celdaSel.x] != m_pCeldas[y][x])
		{
			return true;
		}
	}
	return false;
}
bool CAjedrezView::MoverReinaHacia(int x, int y)
{
	return MoverAlfilHacia(x,y) || MoverTorreHacia(x,y);
}

bool CAjedrezView::EsViaLibre(int x, int y)
{
	int dify = y - m_celdaSel.y;
	int difx = x - m_celdaSel.x;

	bool ok = true;

	if(difx == 0) //Movimiento Vertical
	{		
		for(int i = 1 ; i < abs(dify) ; i++)
		{
			if(m_pCeldas[m_celdaSel.y + (dify<0?-i:i)][m_celdaSel.x] != VACIO)
			{
				ok = false;
			}
		}
	}
	else if(dify == 0) //Movimiento Horizontal
	{
		for(int i = 1 ; i < abs(difx) ; i++)
		{
			if(m_pCeldas[m_celdaSel.y][m_celdaSel.x + (difx<0?-i:i)] != VACIO )
			{
				ok = false;
			}
		}		
	}
	else if(abs(difx) == abs(dify)) //Movimiento diagonal
	{
		for(int i = 1 ; i < abs(dify) ; i++)
		{
			if(m_pCeldas[m_celdaSel.y + (dify<0?-i:i)][m_celdaSel.x + (difx<0?-i:i)] != VACIO)
			{
				ok = false;
			}
		}
	}
	return ok;
}


void CAjedrezView::RealizarMovida(int x, int y)
{
	//Cambiar Turno
	m_bTurnoBlancas      = !m_bTurnoBlancas;

	//Asignar la pieza de origen al destino
	m_pCeldas[y][x] = m_pCeldas[m_celdaSel.y][m_celdaSel.x];

	//TODO: Agregar a la lista de eliminados
	m_pCeldas[m_celdaSel.y][m_celdaSel.x] = VACIO;

	//Soltar la ficha seleccionada
	m_bFichaSeleccionada = false;
	m_celdaSel.x = -1;
	m_celdaSel.y = -1;

	Invalidate();	
}

void CAjedrezView::CancelarMovida(void)
{
	//Soltar la ficha seleccionada
	m_bFichaSeleccionada = false;
	m_celdaSel.x = -1;
	m_celdaSel.y = -1;

	Invalidate();	
}