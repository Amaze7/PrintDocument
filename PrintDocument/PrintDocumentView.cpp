
// PrintDocumentView.cpp : implementation of the CPrintDocumentView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PrintDocument.h"
#endif

#include "PrintDocumentDoc.h"
#include "PrintDocumentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintDocumentView

IMPLEMENT_DYNCREATE(CPrintDocumentView, CView)

BEGIN_MESSAGE_MAP(CPrintDocumentView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPrintDocumentView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPrintDocumentView construction/destruction

CPrintDocumentView::CPrintDocumentView() noexcept
{
	// TODO: add construction code here

}

CPrintDocumentView::~CPrintDocumentView()
{
}

BOOL CPrintDocumentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPrintDocumentView drawing

void CPrintDocumentView::OnDraw(CDC* /*pDC*/)
{
	CPrintDocumentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPrintDocumentView printing


void CPrintDocumentView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPrintDocumentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPrintDocumentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPrintDocumentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPrintDocumentView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPrintDocumentView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPrintDocumentView diagnostics

#ifdef _DEBUG
void CPrintDocumentView::AssertValid() const
{
	CView::AssertValid();
}

void CPrintDocumentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPrintDocumentDoc* CPrintDocumentView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintDocumentDoc)));
	return (CPrintDocumentDoc*)m_pDocument;
}
#endif //_DEBUG


// CPrintDocumentView message handlers
